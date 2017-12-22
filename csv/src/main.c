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
#include "product.h"
#include "product-csv.h"
#include "product-db.h"
#include "log.h"

int main(int argc, char **argv)
{
  LOG("start");

  product_list* list = new_product_list();

  if (argc>1)
    {
      csv_to_product_list(list, argv[1]);
    }
  else
    {
      csv_to_product_list(list, "files/small.csv");
    }
  
  //  print_product_list(list);
  print_product_list_db(list);

  free_product_list(list);

  return 0;
}
