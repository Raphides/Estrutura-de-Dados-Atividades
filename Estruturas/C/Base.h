#ifndef NODE
#define NODE

typedef int element_t;

typedef struct node node_t;

typedef struct node
{
    element_t value;
    node_t *past_node;
    node_t *next_node;
} node_t;


typedef struct
{
    int length;
    node_t *first_node;
    node_t *last_node;
} linked_data_t;


int initList(linked_data_t* data_list);

#endif