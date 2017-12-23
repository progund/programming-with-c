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
#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>

#ifdef DEBUG
//#define LOG(a) fprintf(stderr, "[%s:%d %s()]: %s\n", __FILE__, __LINE__, __func__, a);
#define LOG(a) printf a;  printf("\n");
#define FLOG(a) printf("[%s:%d %s()]: ", __FILE__, __LINE__, __func__); printf a; printf("\n");
#else
#define LOG(a) 
#endif

#endif /* _LOG_H */

