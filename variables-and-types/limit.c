#include <stdio.h>
#include <limits.h>

/* NOT WORKIN on all platforms :(
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
  PRINT_TYPE(char,           CHAR_MIN, CHAR_MAX);
  PRINT_UTYPE(unsigned char, 0,        UCHAR_MAX);
  PRINT_TYPE(short,          SHRT_MIN, SHRT_MAX);
  PRINT_UTYPE(unsigned short,0,        USHRT_MAX);
  PRINT_TYPE(int,            INT_MIN,  INT_MAX);
  PRINT_UTYPE(unsigned int,  0,        UINT_MAX);
  PRINT_TYPE(long,           LONG_MIN, LONG_MAX);
  PRINT_UTYPE(unsigned long, 0,        ULONG_MAX);
*/

#define PRINT_STR_AND_SIZE(a) printf("\n%.20s (%d bytes)\n------------------\n", #a, sizeof(a))

int  main() {
  // char
  PRINT_STR_AND_SIZE(unsigned char);
  printf (" min: %d 0x%x\n", 0, 0);
  printf (" max: %d 0x%x\n", UCHAR_MAX, UCHAR_MAX);

  PRINT_STR_AND_SIZE(char);
  printf (" min: %d 0x%x\n", CHAR_MIN, CHAR_MIN);
  printf (" max: %d 0x%x\n", CHAR_MAX, CHAR_MAX);

  // int
  PRINT_STR_AND_SIZE(unsigned int);
  printf (" min: %d 0x%x\n", 0, 0);
  printf (" max: %ud 0x%x\n", UINT_MAX, UINT_MAX);

  PRINT_STR_AND_SIZE(int);
  printf (" min: %d 0x%x\n", INT_MIN, INT_MIN);
  printf (" max: %d 0x%x\n", INT_MAX, INT_MAX);

  // long int
  PRINT_STR_AND_SIZE(unsigned long int);
  printf (" min: %ld 0x%x\n", 0, 0);
  printf (" max: %lud 0x%llx\n", ULONG_MAX, ULONG_MAX);

  PRINT_STR_AND_SIZE(long int);
  printf (" min: %lld 0x%llx\n", LONG_MIN, LONG_MIN);
  printf (" max: %lld 0x%llx\n", LONG_MAX, LONG_MAX);

  return 0;
}

