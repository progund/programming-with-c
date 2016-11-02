#include <stdio.h>
#include <limits.h>

#define PRINT_TYPE(t, min, max) \
  printf("%.20s\n=======================\n"  \
         " size:     %d byte(s)\n\n"         \
         "  decimal:\n  ------------\n"      \
         "    min: %lld\n"                   \
         "    max: %lld\n"                   \
         "  hexadecimal:\n  ------------\n"  \
         "    min: %llx\n"                   \
         "    max: %llx\n\n",                \
         #t,                                 \
         sizeof(t),                          \
         min, max,                           \
         min, max);

#define PRINT_UTYPE(t, min, max) \
  printf("%.20s\n =======================\n" \
         "  size:     %d byte(s)\n\n"        \
         "  decimal:\n  ------------\n"      \
         "    min: %lld\n"                   \
         "    max: %llu\n"                   \
         "  hexadecimal:\n  ------------\n"  \
         "    min: %llux\n"                  \
         "    max: %llx\n\n",               \
         #t,                                 \
         sizeof(t),                          \
         min, max,                           \
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

