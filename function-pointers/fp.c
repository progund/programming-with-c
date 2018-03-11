/*
 * Copyright (c) 2018, Henrik Sandklef, Rikard Fröberg
 *
 */
#include <stdio.h>

/*
 * Global varible poiting to th feedback function choosen
 *
 */
int (*feedback_fun)(const char *str) ;


/*
 * Name:         default_feedback
 * Args:         str - string to print
 * Description:  Prints a string to given file
 */
int
default_feedback(const char *str)
{
  return fprintf(stderr, "[%s] %s", __func__, str);
}




int main(void)
{
  /* Set feedback_fun to point at default feedback function */
  feedback_fun = default_feedback ;

  /* Call the  default_feedback in the ordinary way */
  printf ("Calling the function the usual way\n");
  default_feedback("Ordinary call\n");

  /* Call the default_feedback through the feedback_fun variable */
  printf ("Calling the function via the function pointer\n");
  feedback_fun("Called using function pointer call\n");
  return 0;
}
