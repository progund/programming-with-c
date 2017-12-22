#include "product.h"
#include "product-csv.h"
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
  
  print_product_list(list);
  print_product_list_db(list);

  free_product_list(list);

  return 0;
}
