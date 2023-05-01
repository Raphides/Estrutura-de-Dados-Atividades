# include <cstdlib>
# include <cstdio>
# include <gtest/gtest.h>
# include "../C/queue.h"
# include "../C/queue.c"

namespace tests {
TEST(queueElementsTest, ultimo)
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
    getElement(fila, 3, num);
    deallocNodes(fila);
    free(fila);
    ASSERT_EQ(num, 66);
    free(num);   
}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
