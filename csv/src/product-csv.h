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
#ifndef _PRODUCT_CSV_H
#define _PRODUCT_CSV_H

#include "product.h"

product_list*
csv_to_product_list(product_list* list, char *file_name);

#endif /* _PRODUCT_CSV_H */
