#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "name.h"

name_list* name_list_new(void)
{
  name_list* tmp = calloc(1, sizeof(name_list));
  if (tmp==NULL)
    {
      return NULL;
    }
  tmp->names=NULL;
  tmp->size=0;

  return tmp;
}

int name_list_add(name_list *list, char *name)
{
  char **new_mem;

  if (list==NULL || name==NULL)
    {
      return NAME_INVALID_PARAM;
    }

  fprintf (stderr, "realloc %p, new size: %d\n",
           (void*)list, list->size+1);

  new_mem = (char**) realloc(list->names, (list->size+1)*sizeof(char*));
  if (new_mem==NULL)
    {
      return NAME_MEM_FAILURE;
    }

  fprintf (stderr, "Assign %p, at: %d  (%s)\n",
           (void*)new_mem, list->size, name);
  new_mem[list->size] = strdup(name);
  if (new_mem[list->size]==NULL)
    {
      return NAME_MEM_FAILURE;
    }
  list->size++;
  list->names = new_mem;
  return NAME_OK;
}

int name_list_remove(name_list *list, char *name)
{
  int pos;
  if (list==NULL || name==NULL)
    {
      return NAME_INVALID_PARAM;
    }
  pos = name_list_positon(list, name);
  if (pos<0)
    {
      return NAME_INVALID_PARAM;
    }
  
  return name_list_remove_at(list, (unsigned int)pos);
}

char* name_list_at_position(name_list *list, unsigned int pos)
{
  if (list==NULL || pos > (list->size))
    {
      return NULL;
    }
  return list->names[pos];
}

int name_list_remove_at(name_list *list, unsigned int pos)
{
  unsigned int j;
  char **new_mem;
  if (list==NULL || pos > (list->size))
    {
      return NAME_INVALID_PARAM;
    }

  fprintf(stderr, "Remove at %d (%s)\n", pos, list->names[pos]);
  FREE_IF_NOT_NULL(list->names[pos]);
  for (j=pos; j<(list->size-1); j++)
    {
      list->names[j] = list->names[j+1];
    }

  list->size--;
  fprintf (stderr, "realloc %p, new size: %d\n",
           (void*)list, list->size);
  new_mem = (char**) realloc(list->names, (list->size+1)*sizeof(char*));
  if (new_mem==NULL)
    {
      return NAME_MEM_FAILURE;
    }
  list->names = new_mem;
  return NAME_OK;          
}

int name_list_positon(name_list *list, char *name)
{
  unsigned int i;
  if (list==NULL || name==NULL)
    {
      return -1;
    }
  for (i=0; i<(list->size); i++)
    {
      char *curr_name = list->names[i];
      if (strncmp(curr_name, name, strlen(curr_name))==0)
        {
          return (int)i;
        }
    }
  return -1;
}


int name_list_print(name_list *list, FILE* stream)
{
  unsigned int i;
  if (list==NULL || stream==NULL)
    {
      return NAME_INVALID_PARAM;
    }
  fprintf(stream, "Names (%d):\n", list->size);
  for (i=0; i<list->size; i++)
    {
      fprintf(stream, "%d %s\n", i, list->names[i]);
    }
  return NAME_OK;
}

int name_list_free(name_list *list)
{
  unsigned int i;
  if (list==NULL)
    {
      return NAME_INVALID_PARAM;
    }
  for (i=0; i<list->size; i++)
    {
      FREE_IF_NOT_NULL(list->names[i]);
    }
  FREE_IF_NOT_NULL(list->names);
  FREE_IF_NOT_NULL(list);
  return NAME_OK;
}
  
int name_list_size(name_list *list)
{
  if (list==NULL)
    {
      return -1;
    }
  return (int) list->size;
}
