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
#ifdef GETLINE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product.h"
#include "product-csv.h"



#ifdef GETLINE
/*@NULL@*/
static char *read_input(FILE* stream)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  read = getline(&line, &len, stream);
  if (read == -1) {
    return NULL;
  }
  return line;
}

#else 
/*@NULL@*/
static char *read_input(FILE *stream)
{
  #define READ_BUF_SIZE 1000
  char buf[READ_BUF_SIZE];
  char *buf_p=buf;
  size_t bytes_read;
  char *ret=NULL;
  size_t size=0;
  char *tmp;
  
  while (1)
    {
      buf_p = fgets(buf, READ_BUF_SIZE, stream);
      if (buf_p==NULL)
        {
          return ret;
        }
      bytes_read = strlen(buf_p);
      size += bytes_read;
      tmp = realloc (ret, size+bytes_read+1);
      if (tmp==NULL)
        {
          // if tmp==NULL, then res is the old mem (not freed)
          // of ret is NULL
          if (ret!=NULL)
            { 
              free (ret);
            }
          return NULL;
        }
      else
        {
          ret = tmp;
        }
      if (size==bytes_read)
        {
          strcpy(ret, buf_p);
        }
      else
        {
          strcat(ret, buf_p);
        }
      if (bytes_read<(READ_BUF_SIZE-1))
        {
          return ret;
        }
    }
  // TODO
  return ret;
}
#endif

static unsigned int strtoint(char *str)
{
  unsigned int value;
  if (str==NULL)
    {
      return 0;
    }
  if (sscanf(str, "%ud", &value)!=1)
    {
      return 0;
    }
  return value;
}

static float strtofloat(char *str)
{
  float value;
  if (str==NULL)
    {
      return 0;
    }
  if (sscanf(str, "%f", &value)!=1)
    {
      return 0;
    }
  return value;
}

static float strtofloat_alc(char *str)
{
  float value;
  if (str==NULL)
    {
      return 0;
    }
  if (sscanf(str, "%f", &value)!=1)
    {
      return 0;
    }
  return value;
}

#define RETURN_IF_NULL(p) if (p==NULL) { printf("return %d\n", __LINE__); return; }



static void
parse_product_line(product_list* list, char *line)
{
  char *tok;
  product* p;
  static const char* delim = ",";

  /* fprintf(stderr, "line: '%s'\n", line); */

  p = add_product(list);
  
  // nr
  tok = strsep(&line, delim);
  set_product_nr(p, strtoint(tok));
  RETURN_IF_NULL(tok);
  // discard artikel-id
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // discard varunummer
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // namn
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_name(p, tok);
  // namn2
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // price
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_price(p, strtofloat(tok));
  
  // pant
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // volume
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_volume(p, strtofloat(tok));
  
  // price per litre
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // sale start
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // out of stock
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // varugrupp
  tok = strsep(&line, delim);
  set_product_group(p, group_to_int(list, tok));
  RETURN_IF_NULL(tok);
  // type
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_type(p, tok);
  
  // style
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_style(p, tok);

  // packing
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // envelope
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // origin
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // origin country
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_country(p, tok);

  // producer
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  set_product_producer(p, tok);
  
  // deliver
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // year
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // year of test
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // alcohol
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  //  printf ("ALCOHOL: '%s'\n", tok);
  set_product_alcohol(p, strtofloat_alc(tok));
  // asortment
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // asortment text
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);
  // eco .....
  tok = strsep(&line, delim);
  RETURN_IF_NULL(tok);

}

product_list*
csv_to_product_list(product_list* list, char *file_name)
{
  FILE *file = fopen(file_name, "r");
  char *line;
  if (file==NULL)
    {
      return NULL; 
    }

  while( (line=read_input(file)) != NULL )
    {
      /* printf("%d '%s'\n", */
      /*        (int)strlen(line), line); */
      if ( strlen(line) > 1 )
        {
          parse_product_line(list, line);
        }
      // The line has been screwed up by strsep so it's unusable
      free(line);
    }

  fclose(file);
  return NULL;
}
