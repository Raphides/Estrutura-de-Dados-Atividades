# include "linkedList.h"
# include <stdlib.h>

void llInit(linked_list_t* list)
{
    list->length = 0;
    linked_list_t* llnew = (linked_list_t*) malloc(sizeof(linked_list_t));
    llnew->first_node = NULL;
    llnew->last_node = NULL;
    llnew->length = 0;
}

int llGet(linked_list_t* list, int index, node_t* result)
{
    if(list == NULL || index >= list->length)
        return 0;
    else
    {
        node_t* result = list->first_node;
        for (int i = 1; i < list->length; i++)
        {
            result = result->next_node;
        }
        return 1;
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
    else if(searchMethod == SIMPLE_SEARCH)
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
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (list->length < 0) //add first element
    {
        list->first_node = new_node;
        list->first_node->value = element;
        list->first_node->next_node = NULL;
        list->first_node->past_node = NULL;
        list->last_node = list->last_node;
        list->length = 1;
        return 1;
    }
    else if ((list->length - 1) == element) // append
    {
        list->last_node->next_node = new_node;
        new_node->past_node = list->last_node;
        new_node->next_node = NULL;
        list->last_node = new_node;
    }
    else if(index == 0) // insert in first position
    {
        list->first_node->past_node = new_node;
        list->first_node = new_node;
        list->first_node->past_node = NULL;
    }
    else
    {
        node_t *moved_node;
        if(!(llGet(list,index,moved_node)))
            return 0;
        moved_node->past_node->next_node = new_node;
        new_node->past_node = moved_node->past_node;
        new_node->next_node = moved_node;
        moved_node->past_node = new_node;
    }
    list->length++;
    return 1;
}

int llExtend(linked_list_t* list, linked_list_t* extension)
{
    if (list == NULL || extension == NULL)
        return 0;
    else if (list->length < 0 || extension->length < 0)
        return 0;
    else
    {
        list->last_node->next_node = extension->first_node;
        extension->first_node->past_node = list->last_node;
        list->length += extension->length;
        free(extension);
    }
}

int llRemove(linked_list_t* list, int index)
{
    node_t* to_free;
    if (list == NULL)
        return 0;
    else if (list->length <= 0 || index >= list->length || list->first_node == NULL || list->last_node == NULL)
        return 0;
    else if (list->length == 1)
    {
        free(list->first_node);
        list->first_node = NULL;
        list->last_node = NULL;
        list->length = 0;
        return 1;
    }
    else if (index == (list->length - 1))
    {
        list->last_node->past_node->next_node = NULL;
        to_free = list->last_node;
        list->last_node = list->last_node->past_node;
    }
    else if (index == 0)
    {
        to_free = list->first_node;
        list->first_node = to_free->next_node;
        list->first_node->past_node = NULL;
    }
    else
    {
        if(!(llGet(list,index,to_free)))
            return 0;
        to_free->next_node->past_node = to_free->past_node;
        to_free->past_node->next_node = to_free->next_node;
    }
    free(to_free);
    list->length--;
    return 1;
}

int llSort(linked_list_t* list, int sortMethod);