# include "sort.h"
# include <stdio.h>
# include <stdlib.h>

int is_viability(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    if (vector == NULL || n_items <= 1 || bytes_per_item == 0 || comparator == NULL)
        return 0;
    else
        return 1;
}

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

void __selectionsort_aux_rec(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    void *lowest = vector;
    void *actual;
    for (int r = 1; r < n_items; r++)
    {
        actual = vector + (r *bytes_per_item);
        if ((*comparator)(lowest, actual) > 0)
            lowest = actual;
    }
    if (lowest != vector)
        __swap_void(lowest, vector, bytes_per_item);
    if (n_items > 2)
        __selectionsort_aux_rec(vector + bytes_per_item, n_items - 1, bytes_per_item, comparator);
}

int bubblesort(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    if (is_viability(vector, n_items, bytes_per_item, comparator))
    {
        __bubblesort_aux_rec(vector, n_items, bytes_per_item, comparator);
        return 1;
    }
    return 0;    
}

int selectionsort(void *vector, size_t n_items, size_t bytes_per_item, int (*comparator)(void *item1, void *item2))
{
    if (is_viability(vector, n_items, bytes_per_item, comparator))
    {
        __selectionsort_aux_rec(vector, n_items, bytes_per_item, comparator);
        return 1;
    }
    return 0;    
}
