#include "product.h"
#include "log.h"

void
print_product_db(product* p)
{
  if(p==NULL)
    {
      return;
    }
  LOG("printing product");
  /* printf("product: %p\n", (void*)p); */
  printf(" * [%s, %d, %f, %f, %s, %s, %s, %s, %s, %f]\n",
         EMPTY_IF_NULL(p->name),
         p->nr, p->price, p->volume,
         EMPTY_IF_NULL(p->type),
         EMPTY_IF_NULL(p->style),
         EMPTY_IF_NULL(p->package),
         EMPTY_IF_NULL(p->country),
         EMPTY_IF_NULL(p->producer),
         p->alcohol);
    }

  
void
print_product_list_db(product_list* list)
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
