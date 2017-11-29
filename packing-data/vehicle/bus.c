#include "bus.h"


#ifndef FAKE_BUS_IMPLEMENTATION
/*
 * This code is compiled IF the macro FAKE_BUS_IMPLEMENTATION is NOT
 * defined
 *
 * Right now this code has no hardware to run - we can imagine it is
 * under development - so we will use a fake implementation.
 */
#error NO BUS IMPLEMENTATION

#else /* FAKE_BUS_IMPLEMENTATION */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include "log/log.h"
#include "vehicle/bus.h"



int
get_bus_data(vehicle_info *vi){
  static int call_cnt ;
  static struct timeval prev_tv;
  long diff_in_usec;
  call_cnt++;

  if (call_cnt==1) {
    srand(time(NULL));
  }

  
  if (vi==NULL) {
    return BUS_BAD_INDATA;
  }

  /* Every 7th call we fake bad data (caused by some glitch in the
     cables).
   */
  if (call_cnt%7==0) {
    return BUS_BAD_DATA;
  }
  if (gettimeofday(&vi->tv, NULL)!=0){
    debug(("gettimeofday failed"));
    return BUS_BAD_DATA;
  }

  if (timeval_diff(&vi->tv, &prev_tv, &diff_in_usec)!=0) {
    return BUS_BAD_DATA;
  }

  if (diff_in_usec>=100000) {
    vi->wheel_speed   = (rand()%30)*100+rand()%30;
    vi->engine_speed  = (rand()%30)*100+rand()%30;
    vi->gear_position = vi->wheel_speed/700;
    prev_tv = vi->tv;
    return BUS_OK;
  }
  return BUS_NO_DATA;
}

int
timeval_diff(struct timeval *tv1, struct timeval *tv2, long *diff) {
  if (tv1==NULL || tv2==NULL || diff==NULL ) {
    return 1;
  }
  long sec_diff     = tv1->tv_sec  - tv2->tv_sec;
  long usec_diff    = tv1->tv_usec - tv2->tv_usec;
  *diff = sec_diff*1000000 + usec_diff;
  
  /* printf ("Diff: %ld  [%ld %ld => %ld   %ld %ld => %ld]\n", */
  /*         diff_in_usec, */
  /*         tv2->tv_sec, tv1.tv_sec, tv1.tv_sec - tv2->tv_sec, */
  /*         tv2->tv_usec, tv1.tv_usec, tv1.tv_usec - tv2->tv_usec */
  /*         ); */
  return 0;
}

void log_vehicle_info(vehicle_info *vi){
  if (vi!=NULL) {
    flog((" vehicle_info: %p ", (void*) vi));
    flog(("[%d, ", vi->gear_position));
    flog(("%.4d, ", vi->wheel_speed));
    flog(("%.4d, ", vi->engine_speed));
    flog(("(%ld.%ld)]\n", vi->tv.tv_sec, vi->tv.tv_usec));
  }
}



#endif /* FAKE_BUS_IMPLEMENTATION */



