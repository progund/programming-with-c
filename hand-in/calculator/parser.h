/** @file parser.h
 *  @brief Function prototypes for the parser module.
 *
 *  @author Henrik Sandklef
 *  @author Rikard Fröberg
 *  @bug most likely tons of it...
 */

#ifndef PARSER_H
#define PARSER_H


#include "expression.h"

/**
 * @brief enum for error codes
 *
 * 
 */
enum {
  SUCCESS,
  SYNTAX_ERROR,
  MISSING_ARGUMENTS
};

/** @brief Parses user arguments in to an expr. The arguments should be the same as supplied to the main function. 
 *
 *  The easiest way to use this function is to pass the main function's arguments, like this
 * <pre>
 * int main(int argc, char** argv)
 * {
 *   int ret;
 *   ret = parse_user_args(argc, argv, &e);
 *   if (ret) 
 *     {
 *      ... handle failed parsing
 *     }
 * </pre>
 *
 *  @param argc number of arguments
 *  @param argv
 *  @param op2 The second operand
 *  @param e A pointer to an expression. This is filled with the parsed data
 *  @return 0 on success, else -1
 */
int
parse_user_args(int argc, char **argv, expr *e);

void usage(FILE *f);

#endif /* PARSER_H */
