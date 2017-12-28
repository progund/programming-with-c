#include "se_juneday_FromCWithLove.h"
#include <stdio.h>
#include <string.h>

#define LOG(a) fprintf(stderr, "[%s:%d] %s\n", __FILE__, __LINE__, a);

JNIEXPORT jstring JNICALL Java_se_juneday_FromCWithLove_getSome
  (JNIEnv *env, jobject obj, jstring msg)
{
#define BUF_SIZE 100
  char buf[BUF_SIZE];
  char *res;
  int len;
  jstring result;
  
  const char *from_java =
    (*env)->GetStringUTFChars(env, msg, NULL);
  if (from_java==NULL)
    {
      return NULL;
    }
  LOG(from_java);

  res=strcpy(buf, "I can C for miles: ");
  LOG(buf);
  
  res=strncat(buf, from_java, BUF_SIZE-strlen(buf)-1);
  if (res==NULL)
    {
      return NULL;
    }
  LOG(buf);
  
  (*env)->ReleaseStringUTFChars(env, msg, from_java);

  result = (*env)->NewStringUTF(env, buf); 

  return result;    
}

