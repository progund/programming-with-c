#include <jni.h>
#include <string.h>
#include <stdlib.h>


static long
setup_jvm(JavaVMOption *options, JavaVM **jvm, JNIEnv **env)
{
  JavaVMInitArgs vm_args;
  long vm_status;

  options[0].optionString = (char*) "-Djava.class.path=." ;
  memset(&vm_args, 0, sizeof(vm_args));
  vm_args.version = JNI_VERSION_1_2;
  vm_args.nOptions = 1;
  vm_args.options = options;
  vm_status = JNI_CreateJavaVM(jvm, (void**)env, &vm_args);

  return vm_status;
}

#define CHECK_START(s) fprintf(stderr, "%-20s", s)

int main()
{
  JavaVMOption options[1];
  JNIEnv *env;
  JavaVM *jvm;

  jclass class;
  jmethodID method;
  jstring message;
  jint sum;
  long vm_status;

  /**
   *
   * Check jvm
   *
   */
  CHECK_START("jvm status:");
  vm_status = setup_jvm(options, &jvm, &env);
  if (vm_status == JNI_ERR)
    {
      fprintf(stderr, " fail\n");
      exit (1);
    }
  fprintf(stderr, " ok\n");




  /**
   *
   * Find class
   *
   */
  CHECK_START("find class: ");
  class = (*env)->FindClass(env, "se/juneday/Stupid");
  if(class ==0)
    {
      fprintf(stderr, " fail\n");
      exit (1);
    }
  fprintf(stderr, " ok\n");
  
  /**
   *
   * Find and use gimmeSum
   *
   */
  CHECK_START("find gimmeSum: ");
  method = (*env)->GetStaticMethodID(env, class, "gimmeSum", "(II)I");
  if(method==0)
    {
      fprintf(stderr, " fail\n");
      exit (1);
    }
  fprintf(stderr, " ok\n");
  
  sum = (*env)->CallStaticIntMethod(env, class, method, 12, 13);
  printf(" ** Result of int method: %d\n", sum);
  
          
  /**
   *
   * Find and use gimmeString
   *
   */
  CHECK_START("find gimmeString: ");
  method = (*env)->GetStaticMethodID(env, class, "gimmeString", "()Ljava/lang/String;");
  if(method==0)
    {
      fprintf(stderr, " fail\n");
      exit (1);
    }
  fprintf(stderr, " ok\n");
  message = (jstring) (*env)->CallStaticObjectMethod(env, class, method);
  const char *from_java =
    (*env)->GetStringUTFChars(env, message, NULL);
  printf(" ** Result of String method: %s\n", from_java);

  (*jvm)->DestroyJavaVM(jvm);
  return 0;
}
