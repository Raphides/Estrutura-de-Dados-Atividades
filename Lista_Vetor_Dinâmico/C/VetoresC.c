# include <stdlib.h>
# include <stdio.h>

typedef char elemento;

int *CriaVetInt(int n_elementos)
{
    if (n_elementos <=0)
        return NULL;
    
    //sizeof(int) == 4
    return (int*) malloc(sizeof(int) * n_elementos);
}

float *CriaVetFloat(int n_elementos)
{
    if (n_elementos <=0)
        return NULL;
    //sizeof(float) == 8
    return (float*) malloc(sizeof(float) * n_elementos);
}

typedef struct Vetor
{
    int ptamax;
    int pqtde;
    elemento* pvet;
} vetor_t;

int inicVet(vetor_t* vetor, int n_elementos){
    if (n_elementos <=0)
        return 1;
    vetor->pvet = (elemento*) malloc(sizeof(elemento) * n_elementos);
    vetor->ptamax = n_elementos;
    vetor->pqtde = 0;
    return 0;
}

int appendVetDesord(vetor_t* vetor, elemento novo_elemento)
{
    if ((vetor->ptamax == vetor->pqtde) || vetor == NULL)
        return 1;
    vetor->pvet[vetor->pqtde] = novo_elemento;
    vetor->pqtde++;
    return 0;
}

int excluirVet(vetor_t* vetor, elemento a_excluir)
{
    for (int elem = 0; elem < vetor->pqtde; elem++)
    {
        if (vetor->pvet[elem] == a_excluir)
        {
            for (int elem_dps = elem; elem_dps < vetor->pqtde - 1; elem_dps++)
            {
                vetor->pvet[elem_dps] = vetor->pvet[elem_dps + 1];
            }
            vetor->pqtde--;
            return 0;
        }
    }
}
/**
 * @brief Busca elementos ou seus supostos lugares num vetor ordenado.
 * 
 * @param vetor ordenado
 * @param valor 
 * @return index de onde o valor deveria estar. Se o valor deveria entre dois valores, o index do maior é retornado.
 */
int busca_binaria(vetor_t* vetor, elemento valor)
{
    if (vetor->pvet[0] > valor)
        return 0;
    else if (vetor->pvet[vetor->pqtde - 1] < valor)
        return vetor->pqtde - 1;
    int index_menor = 0;
    int index_maior = vetor->pqtde - 1;
    int index_meio;
    while (1)
    {
        if (index_menor == index_maior)
        {
            if (vetor->pvet[index_maior] < valor)
                return index_maior + 1;
            else
                return index_maior;
        }
            
        index_meio = (index_menor + index_maior) / 2;
        if (vetor->pvet[index_meio] > valor)
            index_maior = index_meio - 1;
        else if (vetor->pvet[index_meio] < valor)
            index_menor = index_meio + 1;
        else
            return index_meio;
    }
}

int adicVetOrd(vetor_t* vetor, elemento valor)
{
    if ((vetor->ptamax == vetor->pqtde) || vetor == NULL)
        return 1;
    int index = busca_binaria(vetor, valor);
    for (int index_reverso = vetor->ptamax - 1; index_reverso >= index; index_reverso--)
    {
        vetor->pvet[index_reverso + 1] = vetor->pvet[index_reverso];
    }
    vetor->pvet[index] = valor;
}

int main(int argc, char const *argv[])
{
    vetor_t* teste = (vetor_t*) malloc(sizeof(teste));
    inicVet(teste, 10);
    adicVet(teste, 'a');
    adicVet(teste, 'b');
    adicVet(teste, 'c');
    excluirVet(teste, 'a');
    printf("%c %c\n", teste->pvet[0], teste->pvet[1]);
    return 0;
}
