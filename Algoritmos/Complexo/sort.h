# ifndef SORT
# define SORT

#include <stdlib.h>

/**
 * @brief General function to order a item's vector, based on bubble sort method.
 * 
 * Its Big O complexity is O(n²) at worst cases and O(n) in best cases.
 * 
 * @param vector the vector you want to order. Cast it to void
 * @param n_items number of items your vector has.
 * @param bytes_per_item how many bytes each item has. Use sizeof() if you don't know.
 * @param comparator a custom function the user has to create in order to detail how it wants to compare each element.
 * Attention: the function has to return 1 if first item is higher, 0 if they are equal or -1 if second item is higher.
 * @return 1 if the operation succeded, 0 otherwise.
 */
int bubblesort(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2));

/**
 * @brief General function to order a item's vector, based on selection sort method.
 * 
 * Its Big O is O(n²) in all cases.
 * 
 * @param vector the vector you want to order. Cast it to void
 * @param n_items number of items your vector has.
 * @param bytes_per_item how many bytes each item has. Use sizeof() if you don't know.
 * @param comparator a custom function the user has to create in order to detail how it wants to compare each element.
 * Attention: the function has to return 1 if first item is higher, 0 if they are equal or -1 if second item is higher.
 * @return 1 if the operation succeded, 0 otherwise.
 */
int selectionsort(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2));

# endif
