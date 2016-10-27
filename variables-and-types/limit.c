#include <stdio.h>
#include <limits.h>
#include <values.h>


#define PRINT_TYPE(t, min, max) \
  printf("%.20s\n--------------------\n" \
         " %d byte(s)\n"                       \
         " dec:  %lld\n       %lld\n" \
         " hex:  %llx\n       %llx\n\n",    \
         #t, \
         sizeof(t), \
         min, max,  \
         min, max);

#define PRINT_UTYPE(t, min, max) \
  printf("%.20s\n--------------------\n" \
         " %d byte(s)\n"                       \
         " dec:  %lld\n       %llu\n"\
         " hex:  %llux\n       %llux\n\n",    \
         #t, \
         sizeof(t), \
         min, max,  \
         min, max);

int  main() {
  PRINT_TYPE(char,           CHAR_MIN, CHAR_MAX);
  PRINT_UTYPE(unsigned char, 0,        UCHAR_MAX);
  PRINT_TYPE(short,          SHRT_MIN, SHRT_MAX);
  PRINT_UTYPE(unsigned short,0,        USHRT_MAX);
  PRINT_TYPE(int,            INT_MIN,  INT_MAX);
  PRINT_UTYPE(unsigned int,  0,        UINT_MAX);
  PRINT_TYPE(long,           LONG_MIN, LONG_MAX);
  PRINT_UTYPE(unsigned long, 0,        ULONG_MAX);
  return 0;
}

