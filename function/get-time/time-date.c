#include <stdio.h>
#include <time.h>


static struct tm *get_current_time() {
   time_t rawtime;
   struct tm *current_time;

   time(&rawtime);
   current_time = localtime( &rawtime );
   return current_time;
}  

int print_current_date() {
  struct tm *ct = get_current_time();
  printf ("%4d-%2d-%2d %2d:%2d:%2d\n",
          1900+ct->tm_year,
          ct->tm_mon+1,
          ct->tm_mday,
          ct->tm_hour,
          ct->tm_min,
          ct->tm_sec);
}

int current_month() {
  return get_current_time()->tm_mon+1;
}

int current_day() {
  return get_current_time()->tm_mday;
}

int current_year() {
  return get_current_time()->tm_year+1900;
}

int current_sec() {
  return get_current_time()->tm_sec;
}

int current_hour() {
  return get_current_time()->tm_hour;
}

int current_min() {
  return get_current_time()->tm_min;
}

