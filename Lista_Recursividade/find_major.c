# include <stdio.h>
# include <stdlib.h>

int maior_aux(int* vetor, int pos, int ult_index, int maior_atual)
{
    if (vetor[pos] > maior_atual)
        maior_atual = vetor[pos];
    if (pos < ult_index)
        return maior_aux(vetor, pos + 1, ult_index, maior_atual);
    return maior_atual;
}

int maior(int *vetor, int tamanho)
{
    if (vetor == NULL)
        return -1;
    return maior_aux(vetor, 0, tamanho - 1, vetor[0]);
}



int main(int argc, char const *argv[])
{
    int *vetor = (int*) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("Numero %d: ", i);
        scanf("%d", vetor+i);
    }
    printf("Resultado: %d\n", maior(vetor, 10));
    return 0;
}