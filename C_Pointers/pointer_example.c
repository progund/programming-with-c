#include <stdio.h>

void check_pointer() {
  /* declare an integer variable, length, and assign it the value 123 */
  int  length = 123;

  /* declare an "pointer to int" variable, length_ptr */
  int *length_ptr;
  
  /* output the value of length */
  printf ("length, value       %d\n", length);
  /* output the address of length */
  printf ("length, address     %p\n", &length);

  /* assign the variable length_ptr the value "&length", 
     which is the address of length */
  length_ptr = &length;

  /* output the value of length_ptr - 
     which really should be the same as &length as printed before*/
  printf ("length_ptr, value   %p\n", length_ptr);

  /* output the value of what length_ptr points - 
     to do this, we must dereference it*/
  printf ("length_ptr, value   %d\n", *length_ptr);

  printf ("-------------------------\n");
  
  /* assign a new value to the memory points to - 
     to do this, we must dereference it*/
  *length_ptr = 678;
  
  /* output the value of length */
  printf ("length, value       %d\n", length);
  
  /* output the value of what length_ptr points - 
     to do this, we must dereference it*/
  printf ("length_ptr, value   %d\n", *length_ptr);

  /* output the address of length_ptr - 
     which is an address NOT the same as the address of length */
  printf ("length_ptr, address %p\n", &length_ptr);

}

int main() {
  check_pointer();
  return 0;
}
