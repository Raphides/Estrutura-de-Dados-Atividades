# include "Base.h"
# include "stdlib.h"

int initList(linked_data_t* data_list)
{
    data_list->length = 0;
    data_list->first_node = NULL;
    data_list->last_node = NULL;
}