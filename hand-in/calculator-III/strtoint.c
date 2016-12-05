#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include "strtoint.h"

int strtoint(char* str, int* value)
{
  errno = 0;
  char *endptr;
  long val = strtol(str, &endptr, 10);

  if (str==NULL || strlen(str)==0)
    {
      return STRTOINT_INVALID_STRING;
    }
  else if (errno != 0)
    {
      return STRTOINT_ERROR;
    }
  else if (*endptr != '\0')
    {
      return STRTOINT_INVALID_STRING;
    }
  else if (val > INT_MAX)
    {
      return STRTOINT_OVERFLOW;
    }
  else if (val < INT_MIN)
    {
      return STRTOINT_UNDERFLOW;
    }

  *value = (int)val;
  return STRTOINT_OK;
}

