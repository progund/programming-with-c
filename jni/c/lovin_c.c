#include "se_juneday_FromCWithLove.h"
#include <stdio.h>
#include <string.h>

#define LOG(a) fprintf(stderr, "[%s:%d] %s\n", __FILE__, __LINE__, a);

JNIEXPORT jstring JNICALL Java_se_juneday_FromCWithLove_getSome
  (JNIEnv *env, jobject obj, jstring msg)
{
  const char *from_java =
    (*env)->GetStringUTFChars(env, msg, NULL);
  if (from_java==NULL)
    {
      return NULL;
    }
  LOG(from_java);
  return NULL;
}

