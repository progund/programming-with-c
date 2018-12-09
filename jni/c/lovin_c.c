#include "se_juneday_FromCWithLove.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(a) fprintf(stderr, "[%s:%d] C code got \"%s\"\n", __FILE__, __LINE__, a);
const static char* C_MSG_START = "From C code with love, we got \"";
const static char* C_MSG_END = "\"";

JNIEXPORT jstring JNICALL Java_se_juneday_FromCWithLove_getSome
  (JNIEnv *env, jobject obj, jstring msg)
{
  jstring ret_jstring;
  const char *from_java =
    (*env)->GetStringUTFChars(env, msg, NULL);
  if (from_java==NULL)
    {
      return NULL;
    }
  LOG(from_java);

  char * ret_string = calloc(sizeof(char),
                             strlen(from_java) +
                             strlen(C_MSG_START) +
                             strlen(C_MSG_END) +
                             1); 
  if (ret_string == NULL) {
    return NULL;
  }

  // We skip checking return values
  // Since we've allocated (and succeeded in doing so)
  // memory for the entire string the following should work 
  strcpy(ret_string, C_MSG_START);
  strcat(ret_string, from_java);
  strcat(ret_string, C_MSG_END);

  // convert to Jav String
  ret_jstring = (*env)->NewStringUTF(env, ret_string);

  // free (de-allocate) memory of C string
  free (ret_string);
  
  return ret_jstring;
}

