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

#define SET_AND_TEST_VI(vip, gp, sw, es, ret, gpe, swe, ese)            \
  { int __ret;                                                          \
    SET_VI(vip, gp, sw, es);                                            \
    __ret=pack_vechicle_info(&vi, &data);                               \
    assert(__ret==(ret));                                               \
    if (__ret==0) {                                                     \
    unpack_vechicle_info(data, &vi);                                    \
    TEST_VI(&vi, gpe, swe, ese);                                        \
    }                                                                   \
  }
  

int main(void)
{
  vehicle_info vi;
  __uint8_t data;
  int i ;

  printf("Testing gear position (pack and unpack):\n");
  for (i=0; i<20; i++)
    {
      printf ("  gear_position=%d", i);fflush(stdout);
      SET_AND_TEST_VI(&vi, i, 0, 0, (i<=6)?0:1,  i, 0, 0);
      printf(" OK\n");
    }
}
