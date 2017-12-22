/************************************************
 *
 * (c) Rikard Fröberg, Henrik Sandklef 2017
 *
 * License: GPLv3
 * 
 * This piece of code is part of an example showing how to parse a csv
 * file, normalize (think database), and print SQL statements.
 *
 * This code belogs here: 
 *   http://wiki.juneday.se/mediawiki/index.php/Chapter:C_extra_csv
 *
 ************************************************/ 
#ifndef _PRODUCT_H
#define _PRODUCT_H

#define STR_VALUE_MAX_LEN 100
extern const char* EMPTY_STRING;
#define EMPTY_IF_NULL(s) (s==NULL?EMPTY_STRING:s)


typedef struct group_table_
{
  char** names;
  unsigned int size;
} group_table;

typedef struct _product
{
  char  *name;
  unsigned int nr;
  float price;
  float volume;
  int   group;
  char  *type;
  char  *style;
  char  *package;
  char  *country;
  char  *producer;
  float alcohol;
} product;


enum
  {
    PRODUCT_OK,
    PRODUCT_INVALID_ARGUMENTS,
    PRODUCT_FAILURE
  } RETURN_VALUES;

typedef struct _product_list
{
  product*      products;
  unsigned int  size;
  group_table   groups;
} product_list;


product_list*
new_product_list(void);

void
free_product_list(product_list* list);

int
group_to_int(product_list* list, char *group);



product*
add_product(product_list* list);

unsigned int
product_list_size(product_list* list);

void
print_product(product* p);
  
void
print_product_list(product_list* list);

#define set_product_nr(p,n)\
  if (p!=NULL) { p->nr=n; }
#define set_product_price(p, pr)\
  if (p!=NULL) { p->price = pr; }
#define set_product_volume(p, vo)\
  if (p!=NULL) { p->volume=vo; }
#define set_product_alcohol(p, al)\
  if (p!=NULL) { p->alcohol=al; }
#define set_product_group(p, gr)\
  if (p!=NULL) { p->group=gr; }

#define PRODUCT_NAME     1
#define PRODUCT_TYPE     2
#define PRODUCT_STYLE    3
#define PRODUCT_PACKAGE  4
#define PRODUCT_COUNTRY  5
#define PRODUCT_PRODUCER 6
int set_product_str(product *p, char *value, int str_type);
#define set_product_name(p, v) set_product_str(p, v, PRODUCT_NAME)
#define set_product_type(p, v) set_product_str(p, v, PRODUCT_TYPE)
#define set_product_style(p, v) set_product_str(p, v, PRODUCT_STYLE)
#define set_product_package(p, v) set_product_str(p, v, PRODUCT_PACKAGE)
#define set_product_country(p, v) set_product_str(p, v, PRODUCT_COUNTRY)
#define set_product_producer(p, v) set_product_str(p, v, PRODUCT_PRODUCER)



#endif /* _PRODUCT_H */
