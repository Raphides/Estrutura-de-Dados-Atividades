# include <stdio.h>
#include <stdlib.h>

long int somavet(long int *a, int qtde);
long int somavet_aux(long int *a, int qtde);

long int somavet_aux(long int *a, int qtde)
{
    if (qtde == 1)
        return a[0];
    else
        return a[qtde - 1] + somavet_aux(a, qtde - 1);
}

long int somavet(long int *a, int qtde)
{
    if (a == NULL || qtde <= 0)
        return 0;
    else
        return somavet_aux(a, qtde);
    
}

int main(int argc, char const *argv[])
{
    long int* a = (long int*) malloc(100 * sizeof(long int));
    for (int i = 0; i < 100; i++)
        a[i] = i;
    long int sum = somavet(a, 100);
    printf("%ld\n", sum);
    return 0;
}
