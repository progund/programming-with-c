#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>

#ifdef DEBUG
#define LOG(a) fprintf(stderr, "[%s:%d %s()]: %s\n", __FILE__, __LINE__, __func__, a);
#else
#define LOG(a) 
#endif

#endif /* _LOG_H */

