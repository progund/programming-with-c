#include <assert.h>
#include <string.h>
#include "name.h"

#define ASSERT_NAME(names, name, pos) assert(strcmp(name, name_list_at_position(names,pos))==0);

int main(void)
{
  name_list *names = name_list_new();
  int ret;
  assert(name_list_size(names)==0);

  // Add one name: [ "Henrik" ]
  ret = name_list_add(names, "Henrik");
  assert(name_list_size(names)==1);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  
  //  name_list_print(names, stdout);

  // Add one name: [ "Henrik", "Rikard" ]
  ret = name_list_add(names, "Rikard");
  assert(name_list_size(names)==2);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  ASSERT_NAME(names, "Rikard", 1);
  name_list_print(names, stdout);

  // Add one name: [ "Henrik", "Rikard", "Jon" ]
  ret = name_list_add(names, "Jon");
  assert(name_list_size(names)==3);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  ASSERT_NAME(names, "Rikard", 1);
  ASSERT_NAME(names, "Jon", 2);
  name_list_print(names, stdout);

  // Add one name: [ "Henrik", "Rikard", "Jon", "Johan" ]
  ret = name_list_add(names, "Johan");
  assert(name_list_size(names)==4);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  ASSERT_NAME(names, "Rikard", 1);
  ASSERT_NAME(names, "Jon", 2);
  ASSERT_NAME(names, "Johan", 3);
  name_list_print(names, stdout);

  // Add one name: [ "Henrik", "Jon", "Johan" ]
  ret = name_list_remove(names, "Rikard");
  assert(name_list_size(names)==3);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  ASSERT_NAME(names, "Jon", 1);
  ASSERT_NAME(names, "Johan", 2);
  name_list_print(names, stdout);

  // Add one name: [ "Henrik", "Jon", "Johan", "Rikard" ]
  ret = name_list_add(names, "Rikard");
  assert(name_list_size(names)==4);
  assert(ret==NAME_OK);
  ASSERT_NAME(names, "Henrik", 0);
  ASSERT_NAME(names, "Jon", 1);
  ASSERT_NAME(names, "Johan", 2);
  ASSERT_NAME(names, "Rikard", 3);
  name_list_remove_at(names, 1);

  ret = name_list_free(names);
  assert(ret==NAME_OK);
  
  return 0;
}
