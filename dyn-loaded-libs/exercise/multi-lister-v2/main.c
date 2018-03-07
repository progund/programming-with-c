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
  int i;

  fl_plugins* plugins = plugin_new();
  plugin_add(plugins, "plugins/libc-files.so");
  plugin_add(plugins, "plugins/libo-files.so");
  plugin_add(plugins, "plugins/liblib-files.so");
  plugin_add(plugins, "plugins/libmk-files.so");
  
  if (argc>1)
    {
      dir_name = argv[1];
    }

  dir = opendir (dir_name);


  for (i=0 ; i<plugins->size ; i++)
    {
      plugins->plugins[i].info_fun();
    }
  
  if (dir != NULL)
    {
      while ( (dirent = readdir (dir)) )
        {
          ret = 1;
          for (i=0 ; i<plugins->size ; i++)
            {
              
              ret = plugins->plugins[i].present_fun(dirent->d_name);
              if (ret == FILE_LISTER_OK)
                {
                  break;
                }
            }
          if (ret != 0 )
            {
              ret = default_present (dirent->d_name);
              if ( ret != FILE_LISTER_OK )
                {
                  fprintf(stderr, "Failed writing file info. Leaving.\n");
                  break;
                }
            }
        }
      closedir (dir);
    }
  else
    {
      perror ("Couldn't open the directory");
    }


  plugin_free(plugins);
  return 0;
}
