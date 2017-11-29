#include <unistd.h>
#include "vehicle/bus.h"
#include "pack/pack.h"
#include "log/log.h"

#include <math.h>

/*******************
 *
 * Goal: Print mean value (based on the last 10 values) of engine
 * speed (approx.) every second.
 *
 * We'll break this goal down to three smaller tasks, and these into
 * even smaller sub tasks. The sub tasks are close to pseudo code and
 * should, given some thoughts, be possible to translate in to C code
 * - sometimes using one line of code and sometimes using a few lines.
 *
 * You need to find a good place to do place the C code. We will give
 * some hint though.
 *
 * Tasks:
 *
 * 1) Store the value (either the entire struct or just the engine
 *    speed) in an array - store only the last 10 values/structs
 *    1.1) declare an array
 *    1.2) make sure the data is valid (check the return value)
 *    1.3) if not 10 items, store this item
 *         if 10 items, discard the first and store the new item
 *
 * 2) Check if 1 sec has passed since last print out
 *    2.1) declare variables previous_time and current_time (find a suitable type)
 *    2.2) check if previous_time - current_time > 1 sec 
 *    2.3) if the above (2.2) is true store current_time in previous_time
 * 
 * 3) Calc the mean value 
 *    3.1) If one sec has passed (see (2)), calculate mean value of 10
 *         last values of engine_speed and print out the mean value
 *    3.2) If one sec has not passed, do nothing
 *
 ***************************/


int main() {

  vehicle_info vi;
  __uint8_t packed_data;
  /* 1.1 and 2.1 */

  while (1) {
    /*  Debug printout - only seen with
     *   make clean debug 
     */
    debug(("Getting new data\n"));

    get_bus_data(&vi);
    /* 1.2 and 1.3 */

    /* Log the data - only seen with either
     *   make clean log
     *   make clean debug 
     */
    log_vehicle_info(&vi);
    
    /* 2.2 and 2.3 */
    /* 3.1 and 3.2 */

    /* Sleep for 100 useconds, that is 1/10 of second */
    usleep(1000*100);

    pack_vechicle_info(&vi, &packed_data);
    flog(("%d %d %d ===> [%.8x] ",
          vi.gear_position,
          vi.engine_speed,
          vi.wheel_speed,
          packed_data));
    unpack_vechicle_info(packed_data, &vi);
    flog(("===> %d %d %d\n",
          vi.gear_position,
          vi.engine_speed,
          vi.wheel_speed
          ));
    
    
  }

  return 0;
}
