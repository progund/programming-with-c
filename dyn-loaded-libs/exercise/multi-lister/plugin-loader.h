#ifndef PLUGIN_LOADER_H
#define PLUGIN_LOADER_H
#include "interface/file-lister.h"

typedef struct fl_plugin_
{
  present_ptr present_fun;
  info_ptr info_fun;
  void *handle;
} fl_plugin;

typedef struct fl_plugins_
{
  fl_plugin* plugins;
  int size;
} fl_plugins;

int plugin_add(fl_plugins *flps, char *name);

fl_plugins* plugin_new();
void plugin_free(fl_plugins*);


#endif /* PLUGIN_LOADER_H */
