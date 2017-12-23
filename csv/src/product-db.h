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
#ifndef _PRODUCT_DB_H
#define _PRODUCT_DB_H

#include "product.h"

#define PRODUCT_DB products



void
print_product_db(product* p);

void
print_product_list_db(product_list* list);

#endif /* _PRODUCT_DB_H */
