#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#include "interface/file-lister.h"
#include "plugin-loader.h"

static int default_present(char *name)
{
  if (name==NULL)
    {
      return FILE_LISTER_BAD_ARG;
    }
  fprintf(stdout, " --- %s\n", name);
  return FILE_LISTER_OK;
}

int main(int argc, char **argv)
{
  int ret;
  DIR *dir;
  struct dirent *dirent;
  char *dir_name = "./";

  present_ptr present_plugin_fun = load_plugin("plugins/libc-files.so");
  
  
  if (argc>1)
    {
      dir_name = argv[1];
    }

  dir = opendir (dir_name);
  
  if (dir != NULL)
    {
      while ( (dirent = readdir (dir)) )
        {
          ret = present_plugin_fun (dirent->d_name);
          if ( ret == FILE_LISTER_OK )
            {
              continue;
            }
          ret = default_present (dirent->d_name);
          if ( ret != FILE_LISTER_OK )
            {
              fprintf(stderr, "Failed writing file info. Leaving.\n");
              break;
            }
        }
      closedir (dir);
    }
  else
    {
      perror ("Couldn't open the directory");
    }

  return 0;
}
