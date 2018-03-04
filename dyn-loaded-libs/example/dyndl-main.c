#include <dlfcn.h>
#include <stdio.h>

typedef void (*fancy_printing_fun) (char *str);

/* kind of awkward to place these in main
   but let's do that for now and be a bit
   better in the coming chat example */

/* pinter to the print function the so file */
fancy_printing_fun fancy_printing;

/* hande to the so file */
void *handle;

int load_lib(char *libname)
{
  char *error;

  handle = dlopen(libname, RTLD_LAZY);
  if (!handle) {
    fputs (dlerror(), stderr);
    return 1;
  }  

  fancy_printing = dlsym(handle, "fancy_printing");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    return 2;
  }

  return 0;
}


int main(int argc, char **argv)
{
  int ret;
  
  if (argc<2)
    {
      fprintf(stderr, "\nMissing arguments... you must supply the name of a shared object file\n");
      return 1;
    }
  
  ret = load_lib(argv[1]);
  if (ret!=0)
    {
      fprintf(stderr, "\nFailed reading file '%s'\n", argv[1]);
      return 2;
    }

  
  fancy_printing("Wow, we called a function in a file this program had no idea existed\n");


  dlclose(handle);
  return 0;
}
