#ifndef FILE_LISTER_H
#define FILE_LISTER_H

enum
  {
    FILE_LISTER_OK,
    FILE_LISTER_BAD_ARG

  } return_codes;

typedef int (*present_ptr) (char *name);

#endif /* FILE_LISTER_H */
