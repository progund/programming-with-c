#include <sys/time.h>

/* Next lines (#ifndef etc) are outside the scope of the course..  in
   short, they're preventing redefinitions of the enums and funs etc
   by makeint it impossivle to include the code inside the "lock" twice.
*/
#ifndef BUS_H
#define BUS_H

enum vehicle_info {
  BUS_OK,
  BUS_NO_DATA,
  BUS_BAD_INDATA,
  BUS_BAD_DATA
} ;

typedef struct vehicle_info_ {
  unsigned char  gear_position; /* 0 .. 6 */
  unsigned int   wheel_speed;   /* 0 .. 3000 */
  unsigned int   engine_speed;  /* 0 .. 6000 */
  struct timeval tv ; 
} vehicle_info;



int
get_bus_data(vehicle_info *vi);

int
timeval_diff(struct timeval *tv1, struct timeval *tv2, long *diff);

void log_vehicle_info(vehicle_info *vi);

#endif /* BUS_H */


