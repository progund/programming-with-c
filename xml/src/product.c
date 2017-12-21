#include "product.h"
#include "log.h"

product_list*
new_product_list()
{
  LOG("starting");
}

void
free_product_list(product_list* list);

void
add_product(product_list* list, product_list* product);

