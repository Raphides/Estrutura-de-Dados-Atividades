# include <cstdlib>
# include <cstdio>
# include <gtest/gtest.h>
# include "../C/queue.h"
// # include "queue.c"

int main(int argc, char const *argv[])
{
    linked_data_t * fila = (linked_data_t*) malloc(sizeof(linked_data_t));
    initQueue(fila);
    queueElement(fila, 33);
    queueElement(fila, 44);
    queueElement(fila, 55);
    queueElement(fila, 66);
    queueElement(fila, 77);
    unqueueElement(fila);
    element_t* num = (element_t*) malloc(sizeof(element_t));
    printf("Resultado: %d\n", getElement(fila, 3, num));
    printf("Tamanho: %d\nIndex: %d\nElemento: %d\n", fila->length, 3, *num);
    free(num);
    deallocNodes(fila);
    free(fila);
    printf("Success\n");
    return RUN_ALL_TESTS();
}
