#include <math.h>
#include "pack.h"
#include "log/log.h"
#include <assert.h>

int
pack_vechicle_info(vehicle_info* vi, __uint8_t *packed_data)
{
   /* No (really, no!) need to set to 0 
    * Let the compiler check for uninitialised values
    */
  unsigned char wheel_speed;
  unsigned char engine_speed; 
  __uint8_t data;

  if ( (vi->gear_position>6) ||
       (wheel_speed>5) ||
       (engine_speed>8))
    {
      return 1;
    }

  wheel_speed = (vi->wheel_speed) / 800;  /* scale down to 0..4 */
  if (wheel_speed>5) {
    return 1;
  }
  if (vi->engine_speed>3200)
    {
      engine_speed = 8;
    }
  else
    {
      engine_speed = (vi->wheel_speed) / 400;  /* scale down to 0..8 */
    }
  
  data = ((vi->gear_position)<<GEAR_POS_SHIFT) |
     ((wheel_speed)<<WHEEL_SPEED_SHIFT) |
    engine_speed<<ENGINE_SPEED_SHIFT;
  /*  flog(("%d %d %d || %d %d %d ===> [%.8x] ===> %d %d %d\n",
        vi->gear_position,
        vi->engine_speed,
        vi->wheel_speed,
        vi->gear_position,
        engine_speed,
        wheel_speed,
        data,
        (data & GEAR_POS_MASK)>>6,
        (data & ENGINE_SPEED_MASK),
        (data & WHEEL_SPEED_MASK)>>3
       ));
  */
  *packed_data=data;
  return 0;
}

int
unpack_vechicle_info(__uint8_t packed_data, vehicle_info* vi)
{
  vi->gear_position = (packed_data & GEAR_POS_MASK)>>GEAR_POS_SHIFT;
  vi->engine_speed = ((packed_data & ENGINE_SPEED_MASK>>ENGINE_SPEED_SHIFT))*400;
  vi->wheel_speed = ((packed_data & WHEEL_SPEED_MASK)>>WHEEL_SPEED_SHIFT)*800;
  return 0;
}
