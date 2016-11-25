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

#ifndef PARSER_H
#define PARSER_H
#include "sgrep_data.h"


/**
 * @file parser.h
 * @author Henrik Sandklef
 * @brief Functions for parsing command line options
 * @date 9 dec 2015
 *
 * The function is used to parse the command line options. The
 * function stores the information gathered during parsing in the
 * sgrep_data structure.
 *
 */

/* return values */
#define PARSE_OK         0
#define PARSE_BAD_INDATA 1

/**
 * @brief The function parses a command line and stores the settings
 * in the variables in the sgrep_data structure.
 *
 *
 * @param argc - the number of strings to parse
 * @param argv - the strings to parse
 * @param data - a pointer to sgrep_data. Set the variables according to the arguments.
 * @return 0: success, 1: bad indata
 */
int parse(int argc, char **argv, sgrep_data *data); 


#endif /* PARSER_H */

