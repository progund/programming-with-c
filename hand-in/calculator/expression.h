/** @file expression.h
 *  @brief Function prototypes for the expression module
 *
 *  @author Henrik Sandklef
 *  @author Rikard Fröberg
 *  @bug most likely tons of it...
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H


/**
 * @brief enum representing operators as intger values
 *
 * 
 */
enum
  {
    PLUS,
    SUBTRACTION,
    DIVISION,
    MULTIPLICATION,
    REMAINDER
  } operator;

/**
 * @brief Structure to store a valid expression
 *
 * The following expression "1 + 2" is represented with the expr struct like this:
 *   op1 = 1
 *   op  = PLUS
 *   op2 = 2
 *
 */
typedef struct expr_ 
{
  char op;  /** operator (int representation, value range is enum operator) */
  int op1;  /** operand 1 */
  int op2;  /** operand */
} expr;



/** @brief Prints an expression to stdout
 *
 *  @param e A pointer to an expression
 *  @return void.
 */
void
print_expr(expr *e);

/** @brief Turns string representation of two operands and an operator in to an expression
 *
 *  @param op1 The first operand
 *  @param op  The operator
 *  @param op2 The second operand
 *  @param e A pointer to an expression. This is filled with the parsed date
 *  @return 0 on success, else -1
 */
int
args_to_expr(char *op1,
             char *op,
             char *op2,
             expr *e);

int
calc_expression(expr *e, int *result);

#endif  /* EXPRESSION_H */
