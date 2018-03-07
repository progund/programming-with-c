#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "interface/file-lister.h"
#include "plugin-loader.h"

static int load_plugin(char *name, fl_plugin *flp)
{
  char *error;
  
  if ( (name == NULL) || (flp == NULL) )
    {
      return FILE_LISTER_BAD_ARG;
    }
  flp->handle = dlopen(name, RTLD_LAZY);
  if (!flp->handle) {
    fputs (dlerror(), stderr);
    return FILE_LISTER_BAD_ARG;
  }  

  flp->present_fun = (present_ptr) dlsym(flp->handle, "present");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    return FILE_LISTER_BAD_ARG;
  }

  flp->info_fun = (present_ptr) dlsym(flp->handle, "info");
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    return FILE_LISTER_BAD_ARG;
  }

  return FILE_LISTER_OK;
}

int plugin_add(fl_plugins *flps, char *name)
{
  fl_plugin* tmp;
  int ret;
  
  /* If any of the args are NULL, bail out */
  if (flps==NULL || name==NULL)
    {
      return 1;
    }
  
  /* Realloc to tmp */
  tmp =
    realloc(flps->plugins, (flps->size+1)*sizeof(fl_plugin));

  if (tmp==NULL)
    {
      return 1;
    }
  /* Great tmp is not NULL, so we got mem */
  flps->plugins = tmp;

  ret = load_plugin(name, &flps->plugins[flps->size]);
  if (ret!=FILE_LISTER_OK)
    {
      return FILE_LISTER_BAD_ARG;
    }
  flps->size++;

  fprintf(stderr, "loaded : %s\n", name);
  return FILE_LISTER_OK;
}

fl_plugins* plugin_new()
{
  fl_plugins* flps = (fl_plugins*) calloc(1, sizeof(fl_plugins));
  if (flps==NULL)
    {
      return NULL;
    }
  flps->size=0;
  flps->plugins=NULL;
  return flps;
}


void plugin_free(fl_plugins* flps)
{
  int i;
  if (flps==NULL)
    {
      return;
    }

  for (i=0 ; i<flps->size ; i++)
    {
      dlclose(flps->plugins[i].handle);
    }

  free(flps->plugins);

  free(flps);
}

