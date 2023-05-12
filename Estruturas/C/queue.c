# include "queue.h"

# ifdef QUEUE
# include <stdlib.h>

node_t* __getNodeAsc(node_t* first_node, int target, int position);
node_t* __getNodeDesc(node_t* last_node, int target, int position);

int lqInit(linked_queue_t* queue)
{
    queue->length = 0;
    queue->first_node = (node_t*) malloc(sizeof(node_t));
    queue->first_node->past_node = NULL;
    queue->first_node->next_node = NULL;

    queue->last_node = queue->first_node;
    queue->last_node->next_node = NULL;
    queue->last_node->past_node = NULL;
    return 1;
}

int lqAppend(linked_queue_t* queue, element_t value)
{
    if (queue->length == 0)
    {
        queue->first_node->value = value;
    }
    else if (queue->length == 1)
    {
        queue->last_node = (node_t*) malloc(sizeof(node_t));
        queue->first_node->next_node = queue->last_node;
        queue->last_node->value = value;
        queue->last_node->next_node = NULL;
        queue->last_node->past_node = queue->first_node;
    }
    else {
        queue->last_node->next_node = (node_t*) malloc(sizeof(node_t));
        queue->last_node->next_node->past_node = queue->last_node;
        queue->last_node = queue->last_node->next_node;
        queue->last_node->value = value;
        queue->last_node->next_node = NULL;
    }
    queue->length++;
    return 1;
}

int lqPop(linked_queue_t* queue)
{
    if (queue->length == 0)
    {
        return 0;
    }
    else if (queue->length == 1)
    {
        queue->first_node->value = 0;
    }
    else
    {
        queue->last_node = queue->last_node->past_node;
        free(queue->last_node->next_node);
        queue->last_node->next_node = NULL;
    }
    queue->length--;
    return 1;    
}


int lqGet(linked_queue_t* queue, int index, element_t* result)
{
    if (queue->length == 0 || index < 0 || index >= queue->length)
    {
        return 0;
    }
    else if (queue->length == 1 || index == 0)
    {
        *result = queue->first_node->value;
    }
    else if (index == (queue->length - 1))
    {
        *result = queue->last_node->value;
    }
    else
    {
        if (index >= (queue->length / 2))
            *result = __getNodeDesc(queue->last_node, index, (queue->length - 1))->value;
        else
            *result = __getNodeAsc(queue->first_node, index, 0)->value;
    }
    return 1;
}

node_t* __getNodeAsc(node_t* first_node, int target, int position)
{
    if (target != position)
    {
        first_node = first_node->next_node;
        return __getNodeAsc(first_node, target, position + 1);
    }
    else
    {
        return first_node;
    }
    
}

node_t* __getNodeDesc(node_t* last_node, int target, int position)
{
    if (target != position)
    {
        last_node = last_node->past_node;
        return __getNodeDesc(last_node, target, position - 1);
    }
    else
    {
        return last_node;
    }
}

int deallocNodes(linked_queue_t* queue)
{
    node_t* actualNode = queue->first_node;
    for (int l = 0; l < queue->length; l++)
    {
        free(actualNode);
        actualNode = actualNode->next_node;
    }
    return 1;
    
}

# endif