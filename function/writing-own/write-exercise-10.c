#include <stdio.h>
#include "exam.h"

/*
 *
 * The test belows are by no means an optimal way to write tests, but
 * they will do for now
 *
 */

int main(int argc, char **argv)
{

  printf ("Testing exam grade\n");
  if (exam_grade(-1)!=-1)
    {
      printf("-1 failed\n");
    }
  if (exam_grade(0)!=0)
    {
      printf("0 failed\n");
    }
  if (exam_grade(24)!=0)
    {
      printf("24 failed\n");
    }
  if (exam_grade(25)!=1)
    {
      printf("25 failed\n");
    }
  if (exam_grade(37)!=1)
    {
      printf("37 failed\n");
    }
  if (exam_grade(38)!=2)
    {
      printf("38 failed\n");
    }
  if (exam_grade(51)!=-1)
    {
      printf("51 failed\n");
    }
  printf ("All tests passed if no fail messages abve\n");

  
}
