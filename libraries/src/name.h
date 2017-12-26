#ifndef NAME_H
#define NAME_H
#include <stdio.h>

typedef struct name_list_
{
  char** names;
  unsigned int size;
} name_list;

/**
 * @brief Returns a pointer to a name_list struct (dynamically allocated).
 * @return A pointer to the allocated memory. NULL is returned if memory allocation fails
 */
name_list* name_list_new(void);

/**
 * @brief Adds name name_list struct. The string is copied and memory has been created for it using the alloc family.
 * @param list the list to add name to
 * @param name the name to add 
 * @return NAME_OK (0) on success. 
 */
int name_list_add(name_list *list, char *name);

/**
 * @brief Removes the first occurance of name in the list. The string
 * is freed and the names afterwards are copied down. The size of the list is alos adjusted (with -1) on success.
 * @param list the list to remove name from
 * @param name to remove
 * @return NAME_OK (0) on success.
 */
int name_list_remove(name_list *list, char *name);

/**
 * @brief Removes the name at a given position in the list. The string
 * is freed and the names afterwards are copied down. The size of the list is alos adjusted (with -1) on success.
 * @param list the list to remove name from
 * @param pos the position of the name to remove
 * @return NAME_OK (0) on success.
 */
int name_list_remove_at(name_list *list, unsigned int pos);

/**
 * @brief Returns the position of the name in the list
 * @param list the list to get the position of name from
 * @param name the name to search for
 * @return NAME_OK (0) on success.
 */
int name_list_positon(name_list *list, char *name);

/**
 * @brief Prints (to stream) the entire list of names.
 * @param list the list to get the position of name from
 * @param stream where to print
 * to add @return NAME_OK (0) on success.
 */
int name_list_print(name_list *list, FILE* stream);

/**
 * @brief Frees all the memory used by the list
 * @param list the list to free
 * @return NAME_OK (0) on success.
 */
int name_list_free(name_list *list);

/**
 * @brief Frees all the memory used by the list
 * @param list the list to free
 * @return NAME_OK (0) on success.
 */
int name_list_size(name_list *list);

/**
 * @brief Returns the name at position in the list
 * @param list the list to get the name (at position) from
 * @param pos the position to get the name
 * @return NAME_OK (0) on success.
 */
char* name_list_at_position(name_list *list, unsigned int pos);

#define FREE_IF_NOT_NULL(p) if (p!=NULL) { free(p); }
enum
  {
    NAME_OK,
    NAME_INVALID_PARAM,
    NAME_MEM_FAILURE,
    NAME_INVALID_NAME,
    NAME_INVALID_POSITION
  } RET_VAL;

#endif /* NAME_H */

