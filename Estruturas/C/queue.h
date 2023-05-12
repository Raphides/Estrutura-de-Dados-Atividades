# ifndef QUEUE
# define QUEUE
# include "Base.h"

typedef linked_data_t linked_queue_t;

/**
 * @brief initializate Queue data structure.
 * @param queue adress to target queue.
 * Previous allocation of the pointer is needed.
 * @return 0 for sucess, 1 for error
 */
int lqInit(linked_queue_t* queue);

/**
 * @brief add an element to the end of the queue.
 * @param queue adress to target queue.
 * @param value value to be assigned in the end of the queue.
 * @return 0 for sucess, 1 for error
 */
int lqAppend(linked_queue_t* queue, element_t value);

/**
 * @brief delete the first element at the queue.
 * 
 * @param queue adress to target queue.
 * @return 0 for sucess, 1 for error
 */
int lqPop(linked_queue_t* queue);

/**
 * @brief Get an element from a specific position at the queue.
 * 
 * @param queue adress to target queue.
 * @param index position to take the element.
 * @return 0 for sucess, 1 for error
 */
int lqGet(linked_queue_t* queue,  int index, element_t* result);


/**
 * @brief Free all the previous allocated memory from the queue.
 * 
 * @param queue adress to target queue.
 * @return 0 for sucess, 1 for error
 */
int deallocNodes(linked_queue_t* queue);

#endif