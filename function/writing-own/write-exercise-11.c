#include <stdio.h>
#include "exam.h"

/*
 *
 * The tests below are by no means an optimal way to write tests, but
 * they will do for now
 *
 */

int main(int argc, char **argv)
{

  printf ("Testing course grade\n");
  if (course_grade(-1,-1)!=-1)
    {
      printf("-1,-1 failed\n");
    }
  if (course_grade(0,0)!=0)
    {
      printf("0,0 failed\n");
    }
  if (course_grade(0,1)!=0)
    {
      printf("0,1 failed\n");
    }
  if (course_grade(1,0)!=0)
    {
      printf("1,0 failed\n");
    }
  if (course_grade(1,1)!=1)
    {
      printf("1,1 failed\n");
    }
  if (course_grade(2,1)!=2)
    {
      printf("2, 1 failed\n");
    }
  if (course_grade(2,2)!=-1)
    {
      printf("2, 2 failed\n");
    }
  printf ("All tests passed if no fail messages abve\n");
  
}
