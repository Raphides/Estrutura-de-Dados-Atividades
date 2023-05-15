#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int comparator(void *item1, void *item2)
{
    int *num1 = (int *) item1;
    int *num2 = (int *) item2;
    if ((*num1) > (*num2))
        return 1;
    else if ((*num1) == (*num2))
        return 0;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int *teste = (int *) malloc(4*4); 
    teste[0] = 3;
    teste[1] = 2;
    teste[2] = 1;
    if (bubblesort((void*)teste, 3, sizeof(int), comparator))
    {
        printf("Sucess\n");
        printf("%d %d %d\n", teste[0], teste[1], teste[2]);
    }
    else
        printf("Fail\n");
    
    return 0;
}
