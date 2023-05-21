# include "Base.h"

typedef linked_data_t linked_list_t;

enum searchMethods{
    SIMPLE_SEARCH, BINARY_SEARCH
};

enum sortMethods{
    BUBBLE_SORT, SELECTION_SORT, INSERT_SORT, MERGE_SORT, QUICK_SORT
};

void llInit(linked_list_t* list);

int llGet(linked_list_t *list, int index, node_t* result);

int llInsert(linked_list_t* list, int index, element_t element);

int llExtend(linked_list_t* list, linked_list_t* extension);

int llRemove(linked_list_t* list, int index);

int llSort(linked_list_t* list, int sortMethod);

/**
 * @brief 
 * 
 * @param list linked list adress already initializated.
 * @param searchMethod refered to the searchMethods enum. 0 if you want a simple search, 1 to a binary search.
 * @param element 
 * @return positive index numbers if the if the target element was found, -1 if it was not found and -2 if the list was empty.
 */
int llSearch(linked_list_t* list, int searchMethod, element_t element);