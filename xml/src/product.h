#ifndef _PRODUCT_H
#define _PRODUCT_H

#define DEFAULT_STR_SIZE 60

typedef struct _product
{
  char  name[DEFAULT_STR_SIZE];
  int   nr;
  float price;
  float volume;
  char  type[DEFAULT_STR_SIZE];
  char  style[DEFAULT_STR_SIZE];
  char  package[DEFAULT_STR_SIZE];
  char  country[DEFAULT_STR_SIZE];
  char  producer[DEFAULT_STR_SIZE];
  float alcohol;
} product;


typedef struct _product_list
{
  product* products;
  int      index;
} product_list;


product_list*
new_product_list();

void
free_product_list(product_list* list);

void
add_product(product_list* list, product_list* product);


#endif /* _PRODUCT_H */
