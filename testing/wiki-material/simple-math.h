
int
max(int a, int b);

int
min(int a, int b);

int
mean(int *array, int size, int *result);

#ifdef  ENABLE_DEBUG
#define DEBUG_INFO() fprintf(stderr, "\n ** Debug and test compiled: %s %s **\n\n ",__DATE__,  __TIME__); 
#define DEBUG(a, ...) fprintf(stderr, "[%s:%s():%d] ",__FILE__,__func__, __LINE__ ); fprintf(stderr, a, __VA_ARGS__);
#define DEBUG_INT_VAR(a) fprintf(stderr, "[%s:%s():%d] ",__FILE__,__func__, __LINE__ ); fprintf(stderr, "%s=%d\n", #a, a);
#else
#define DEBUG(a, ...) 
#define DEBUG_INFO() 
#define DEBUG_INT_VAR(a) 
#endif
