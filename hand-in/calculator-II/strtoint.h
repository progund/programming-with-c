#ifndef STRTOINT_H
#define STRTOINT_H

enum
  {
    STRTOINT_OK,
    STRTOINT_OVERFLOW,
    STRTOINT_UNDERFLOW,
    STRTOINT_INVALID_STRING,
    STRTOINT_ERROR
  };

int strtoint(char* str, int* value);

#endif /* STRTOINT_H */
