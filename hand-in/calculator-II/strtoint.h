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


/*
 * Returns status 
 *    0 - if ok
 *    not 0 - on failure (see enum)
 *
 * Parameters:
 *   str - the string to convert to int
 *   value - a pointer to an int where the result shalt be stored
 */
int strtoint(char* str, int* value);

#endif /* STRTOINT_H */
