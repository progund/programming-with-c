#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>

#define LOG(a) fprintf(stderr, "[%s:%d %s()]: %s\n", __FILE__, __LINE__, __func__, a);

#endif /* _LOG_H */

