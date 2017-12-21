#include <stdio.h>
#include <assert.h>
#include "vehicle/bus.h"
#include "pack/pack.h"

#define SET_VI(vip, gp, sw, es)                   \
  (vip)->gear_position=gp;                        \
  (vip)->wheel_speed=sw;                          \
  (vip)->engine_speed=es;                         \
  (vip)->tv.tv_sec=0;                             \
  (vip)->tv.tv_usec=0;                            \
  

#define TEST_VI(vip, gp, sw, es)                         \
  assert(((vip)->gear_position)==gp);                    \
  assert(((vip)->wheel_speed)==sw);                      \
  assert(((vip)->engine_speed)==es);                     

#define SET_AND_TEST_VI(vip, gp, sw, es, gpe, swe, ese) \
  SET_VI(vip, gp, sw, es);                              \
  pack_vechicle_info(&vi, &data);                       \
  unpack_vechicle_info(data, &vi);                      \
  TEST_VI(&vi, gpe, swe, ese);                  
  

int main(void)
{
  vehicle_info vi;
  __uint8_t data;
  
  SET_AND_TEST_VI(&vi, 0, 0, 0,   0, 0, 0);
  SET_AND_TEST_VI(&vi, 1, 1, 1,   1, 0, 0);
}
