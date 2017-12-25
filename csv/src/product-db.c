/************************************************
 *
 * (c) Rikard Fröberg, Henrik Sandklef 2017
 *
 * License: GPLv3 or later
 * 
 * This piece of code is part of an example showing how to parse a csv
 * file, normalize (think database), and print SQL statements.
 *
 * This code belogs here: 
 *   http://wiki.juneday.se/mediawiki/index.php/Chapter:C_extra_csv
 *
 ************************************************/ 
#include "product.h"
#include "log.h"

void
print_product_db(product* p)
{
  if(p==NULL)
    {
      return;
    }
  //INSERT INTO product VALUES(8219006,'Gosset Grand Millésime',1288.0,12.0,1500,4,'Vitt Torrt');
  
  printf("INSERT INTO product VALUES(%d, \"%s\", %.2f, %.2f, %d, %d, '%s');\n",
         p->nr,
         EMPTY_IF_NULL(p->name),
         p->price,
         p->alcohol,
         (int)p->volume,
         p->group,
         EMPTY_IF_NULL(p->type));
}

static void print_groups(product_list* list)
{
  unsigned i;
  group_table* g = &list->groups;
  for (i=0; i<(g->size); i++)
    {
      printf("INSERT INTO productGroup VALUES(%d, \"%s\");\n",
             i, EMPTY_IF_NULL(g->names[i]));
             
    }
}
  
void
print_product_list_db(product_list* list)
{
  /*
    CREATE TABLE productGroup(id INT PRIMARY KEY NOT NULL, name text);
    CREATE TABLE product(nr INT primary key not null, name text, price REAL, alcohol REAL, volume INT, productGroupId INT, type text, foreign key(productGroupId) references productGroup(id));
  */
  unsigned int i;
  if (list==NULL)
    {
      return;
    }
  LOG(("printing product list"));
  printf("CREATE TABLE productGroup(id INT PRIMARY KEY NOT NULL, name text);\n");
  printf("CREATE TABLE product(nr INT primary key not null, name text, price REAL, alcohol REAL, volume INT, productGroupId INT, type text, foreign key(productGroupId) references productGroup(id));\n");

  print_groups(list);
  
  for (i=0; i<(list->size); i++)
    {
      LOG(("print at pos: %d\n", i));
      print_product_db(&list->products[i]);
    }
}
