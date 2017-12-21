#include <stdio.h>


#ifdef LOG_TO_FILE
#define flog(a)   printf a ;
#else
#define flog(a) 
#endif

#ifdef DEBUG
#define debug(a) printf("[%s::%s():%d]: ", __FILE__, __func__, __LINE__); printf  a ;
#else
#define debug(a)
#endif

