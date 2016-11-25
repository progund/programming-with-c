/*****
 *       grep example
 *                                                                   
 *  Copyright (C) 2015 Henrik Sandklef 
 *                                                                   
 * This program is free software; you can redistribute it and/or     
 * modify it under the terms of the GNU General Public License       
 * as published by the Free Software Foundation; either version 3    
 * of the License, or any later version.                             
 *                                                                   
 *                                                                   
 * This program is distributed in the hope that it will be useful,   
 * but WITHOUT ANY WARRANTY; without even the implied warranty of    
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     
 * GNU General Public License for more details.                      
 *                                                                   
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software       
 * Foundation, Inc., 51 Franklin Street, Boston,            
 * MA  02110-1301, USA.                                              
 ****/

#ifndef SEARCHER_H
#define SEARCHER_H
#include "sgrep_data.h"

/**
 * @file searcher.h
 * @author Henrik Sandklef
 * @brief Functions for finding string in lines (strings)
 * @date 9 dec 2015
 *
 * These functions are used to search for strings in string. The
 * functions keep track of the number of matches and the search string
 * itself by using the corrsponding variables in the sgrep_data
 * struct.
 *
 */

#define SEARCHER_OK_MATCHES    0
#define SEARCHER_OK_NO_MATCHES 1
#define SEARCHER_BAD_INDATA    2
#define SEARCHER_OUT_OF_MEM 2



/**
 * @brief Searches for a string (found in sdg) in indata.
 *
 * Given a valid search string (the needle), in the variable reg_exp
 * in sgrep_data this functions checks if the string can be found in
 * the indata (haystack).
 *
 * If any of the indata is NULL, the function returns 2.
 *
 * @param in - streams to find lines in, which in turn will be checked for matches
 * @param sdg - struct containing string to search for
 * @return 0: at least on match, 1: no matches found, 2: bad indata
 */
int
search_string(char *indata, sgrep_data* sdg);

/**
 * @brief The function searches for regexp in each line of the FILE in
 *
 * Given a valid search string (the needle), in the variable reg_exp
 * in sgrep_data this functions checks if the string can be found in
 * each of the lines in the variable in in sgred_data.
 *
 * If any of the indata is NULL, the function returns 2.
 *
 * \note This function is allowed to print matching strings to stdout. It should be noted that it would be better to leave this to some other module.
 *
 *
 * @param sdg - struct containing string to search for and file where to search in
 * @return 0: at least on match, 1: no matches found, 2: bad indata
 */
int
search_file(sgrep_data *sdg);


/**
 * @brief The function frees all allocated data in the sgrep_data
 * struct supplied as an argument
 *
 * @param sgd - the data to free
 */
void free_data(sgrep_data *sgd) ;


#endif /* SEARCHER_H */
