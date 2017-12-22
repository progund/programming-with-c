#include <stdlib.h>
#include <string.h>

#include "product.h"
#include "log.h"

#define FREE_IF_NOT_NULL(p) if (p!=NULL) {/*LOG(" ** free()"); */ free(p);}
#define SET_NULL(p) p=NULL

const char* EMPTY_STRING="";

product_list*
new_product_list()
{
  LOG("creating new");
  product_list* list =
    calloc(sizeof(product_list), 1);
  
  if (list==NULL)
    {
      return NULL;
    }
  list->size = 0;
  list->products = NULL;
  return list;
}

static void free_group_table(group_table *t)
{
  unsigned int i;
  LOG("freeing table");
  for (i=0; i<(t->size); i++)
    {
      free(t->names[i]);
    }
  free(t->names);
  t->names=NULL;
}

void
free_product_list(product_list* list)
{
  unsigned int i;
  if (list==NULL)
    {
      return;
    }
  LOG("freeing");

  free_group_table(&list->groups);
  
  for (i=0; i<(list->size); i++)
    {
      /* fprintf(stderr, "free at pos: %d\n", i); */
      product* p = &(list->products[i]);
      FREE_IF_NOT_NULL(p->name);
      FREE_IF_NOT_NULL(p->type);
      FREE_IF_NOT_NULL(p->style);
      FREE_IF_NOT_NULL(p->package);
      FREE_IF_NOT_NULL(p->country);
      FREE_IF_NOT_NULL(p->producer);
    }
  
  // Some implementations of free discard null. Let's not rely on
  // that.
  FREE_IF_NOT_NULL(list->products);
  FREE_IF_NOT_NULL(list);
}


product*
add_product(product_list* list)
{
  product* tmp_list;
  product *p;
  LOG("add_product");
  if (list==NULL)
    {
      return NULL;
    }
  /* fprintf(stderr, "Increase to %d\n", (list->size)+1); */
  
  /* fprintf(stderr, "Alloc to %p size: %ld\n", */
  /*         (void*) list->products, sizeof(product)*((list->size)+1));  */
  tmp_list = (product*) realloc(list->products, sizeof(product)*((list->size)+1));
  if (tmp_list==NULL)
    {
      return NULL;
    }
  list->products = tmp_list;
  p = &list->products[list->size];
  SET_NULL(p->name);
  SET_NULL(p->type);
  SET_NULL(p->style);
  SET_NULL(p->package);
  SET_NULL(p->country);
  SET_NULL(p->producer);
  p->nr=0;
  p->price=0;
  p->volume=0;
  p->alcohol=0;

  list->size++;
  return &list->products[list->size-1]; // or &list->products[list->size++-1] ;)
}


unsigned int
product_list_size(product_list* list)
{
  LOG("size");
  if (list==NULL)
    {
      return PRODUCT_INVALID_ARGUMENTS;
    }
  return list->size;
}



int
set_product_str(product *p, char *value, int str_type)
{
  char *copy;
  if ( (p==NULL || value==NULL) )
    {
      return PRODUCT_INVALID_ARGUMENTS;
    }
  copy = strndup(value, STR_VALUE_MAX_LEN);
  if ( copy==NULL )
    {
      return PRODUCT_INVALID_ARGUMENTS;
    }
  // remove trailing newline
  int len = (int)strlen(copy);
  if (len>1)
    {
      if (copy[len-1]=='\n')
        {
          copy[strlen(copy)-1]='\0' ;
        }
    }
  
  
  if (copy==NULL)
    {
      return PRODUCT_FAILURE;
    }
  switch (str_type)
    {
    case PRODUCT_NAME:
      p->name=copy;
      break;
    case PRODUCT_TYPE:
      p->type=copy;
      break;
    case PRODUCT_STYLE:
      p->style=copy;
      break;
    case PRODUCT_PACKAGE:
      p->package=copy;
      break;
    case PRODUCT_COUNTRY:
      p->country=copy;
      break;
    case PRODUCT_PRODUCER:
      p->producer=copy;
      break;
    default:
      return PRODUCT_FAILURE;
    }
  /* fprintf(stderr, "copied %s\n", copy); */
  return PRODUCT_OK;
}

void
print_product(product* p)
{
  if(p==NULL)
    {
      return;
    }
  LOG("printing product");
  /* printf("product: %p\n", (void*)p); */
  printf(" * [%s, %d, %d, %f, %f, %s, %s, %s, %s, %s, %f]\n",
         EMPTY_IF_NULL(p->name),
         p->group,
         p->nr, p->price, p->volume,
         EMPTY_IF_NULL(p->type),
         EMPTY_IF_NULL(p->style),
         EMPTY_IF_NULL(p->package),
         EMPTY_IF_NULL(p->country),
         EMPTY_IF_NULL(p->producer),
         p->alcohol);
    }

  
void
print_product_list(product_list* list)
{
  unsigned int i;
  if (list==NULL)
    {
      return;
    }
  LOG("printing product list");
  printf("Printing product list (%d products)\n", list->size);
  for (i=0; i<(list->size); i++)
    {
      /* fprintf(stderr, "print at pos: %d\n", i); */
      print_product(&list->products[i]);
    }
}

int
group_to_int(product_list* list, char *group)
{
  int i;
  char** tmp_ptr;
  group_table* groups;
  
  if (group==NULL || list==NULL)
    {
      return -1;
    }

  groups = &list->groups; 
  /* fprintf(stderr, "group_to_int(%s)  (size:%d)\n", */
  /*         group, groups->size); */
  for (i=0; i<(int)(groups->size); i++)
    {
      /* fprintf(stderr, " * %s\n", groups->names[i]); */
      if (strncmp(groups->names[i], group, strlen(group))==0)
        {
          /* fprintf(stderr, " * %s => %d \n", groups->names[i], i); */
          return i;
        }
    }
  
  /* fprintf(stderr, "new: %s\n", group); */
  tmp_ptr = realloc(groups->names, sizeof(char*)*(groups->size+1));
  if (tmp_ptr==NULL)
    {
      return -2;
    }
  groups->names = tmp_ptr;

  groups->names[groups->size]=strdup(group);
  groups->size++;  
  /* fprintf(stderr, "new: %s => %d \n", groups->names[i], (int)((groups->size)-1)); */
  return (int)(groups->size-1);
}

