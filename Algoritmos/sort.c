# include "sort.h"
# include <stdio.h>
# include <stdlib.h>

void __swap_void(void *item1, void *item2, size_t bits_per_item)
{
    char *i1 = (char *) item1;
    char *i2 = (char *) item2;
    char __temp;
    for (size_t j = 0; j < bits_per_item; j++)
    {
        __temp = i1[j];
        i1[j] = i2[j];
        i2[j] = __temp;
    }
}

void __bubblesort_aux_rec(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    void *actual_adress, *next_adress;
    int was_ordered = 1;
    for (int i = 0; i < n_items - 1; i++)
    {
        actual_adress = vector + (i * bytes_per_item);
        next_adress = vector + ((i+1) * bytes_per_item);
        if ((*comparator)(actual_adress, next_adress) > 0)
        {
            __swap_void(actual_adress, next_adress, bytes_per_item);
            was_ordered = 0;
        }
    }
    if (!was_ordered)
        __bubblesort_aux_rec(vector, n_items, bytes_per_item, comparator);   
}

int bubblesort(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    if (vector == NULL || n_items == 0 || bytes_per_item == 0 || comparator == NULL)
        return 0;
    else
        __bubblesort_aux_rec(vector, n_items, bytes_per_item, comparator);
        return 1;    
}

