# include "linkedList.h"
# include <stdlib.h>

int llInit(linked_list_t* list)
{
    list->length = 0;
    linked_list_t* llnew = (linked_list_t*) malloc(sizeof(linked_list_t));
    llnew->first_node = NULL;
    llnew->last_node = NULL;
    llnew->length = 0;
}

int llget(linked_list_t* list, int index, element_t* result)
{
    if(list == NULL)
        return 0;
    else
    {
        node_t* __result = list->first_node;
        for (int i = 1; i < list->length; i++)
        {
            __result = __result->next_node;
        }
        return __result->value;
    }
}

int llSearch(linked_list_t* list, int searchMethod, element_t target)
{
    if(list == NULL || list->length <= 0)
        return -2;
    else if(target == list->first_node->value)
        return 0;
    else if(target == list->last_node->value)
        return list->length - 1;
    else if(searchMethod == SIMPLE)
    {
        node_t* __node = list->first_node;
        
        for (int q = 1; q < list->length - 1; q++)
        {
            __node = __node->next_node;
            if (__node->value == target)
                return q;
        }
        return -1;
    }
    
}

int llInsert(linked_list_t* list, int index, element_t element)
{
    if(list == NULL)
        return 0;
    else if (list->length < 0)
    {
        list->first_node = (node_t*) malloc(sizeof(node_t));
        list->first_node->value = element;
        list->first_node->next_node = NULL;
        list->first_node->past_node = NULL;
        list->last_node = list->last_node;
        list->length = 1;
    }
    else
    {
        
    }
    
}

int llExtend(linked_list_t* list);

int llRemove(linked_list_t* list);

int llSort(linked_list_t* list, int sortMethod);