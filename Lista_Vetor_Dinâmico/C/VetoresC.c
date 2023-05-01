# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef char elemento;

int definirElemento(int tipo)
{
    switch (tipo)
    {
    case 1:
        typedef char elemento; 
        break;
    case 2:
        typedef int elemento; 
        break;
    default:
        return false;
        break;
    }
}

// questão 1a

int *CriaVetInt(int n_elementos)
{
    if (n_elementos <=0)
        return NULL;
    
    //sizeof(int) == 4
    return (int*) malloc(sizeof(int) * n_elementos);
}

// questão 1b

float *CriaVetFloat(int n_elementos)
{
    if (n_elementos <=0)
        return NULL;
    //sizeof(float) == 8
    return (float*) malloc(sizeof(float) * n_elementos);
}

// Questão 3

typedef struct Vetor
{
    int ptamax;
    int pqtde;
    elemento* pvet;
} vetor_t;

int inicVet(vetor_t* vetor, int n_elementos){
    if (n_elementos <=0)
        return false;
    vetor->pvet = (elemento*) malloc(sizeof(elemento) * n_elementos);
    vetor->ptamax = n_elementos;
    vetor->pqtde = 0;
    return true;
}

int desalocVet(vetor_t* vetor)
{
    free(vetor->pvet);
}

// questão 3a

int adicVet(vetor_t* vetor, elemento novo_elemento)
{
    if ((vetor->ptamax == vetor->pqtde) || vetor == NULL)
        return false;
    vetor->pvet[vetor->pqtde] = novo_elemento;
    vetor->pqtde++;
    return true;
}

// questão 3b

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
            return true;
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
        return vetor->pqtde;
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

// questão 4a

int adicVetOrd(vetor_t* vetor, elemento valor)
{
    if ((vetor->ptamax == vetor->pqtde) || vetor == NULL)
        return false;
    int index = busca_binaria(vetor, valor);
    for (int index_reverso = vetor->pqtde - 1; index_reverso >= index; index_reverso--)
        vetor->pvet[index_reverso + 1] = vetor->pvet[index_reverso];
    vetor->pvet[index] = valor;
    vetor->pqtde++;
    return true;
}

// questão 5

int excluirVetOrd(vetor_t* vetor, elemento valor)
{
    if (vetor->pqtde <= 0 || vetor == NULL)
        return false;
    int index = busca_binaria(vetor, valor);
    if (vetor->pvet[index] != valor)
        return false;
    else
    {
        for (int index_aux = index; index_aux < vetor->pqtde - 1; index_aux++)
            vetor->pvet[index_aux] = vetor->pvet[index_aux + 1];
        vetor->pqtde--;
    }
}


void printVet(vetor_t* vetor)
{
    for (int m = 0; m < vetor->pqtde; m++)
        printf("%c ", vetor->pvet[m]);
    printf("\n");
}

// Questão 6

int cmpVet(vetor_t* vetor1, vetor_t* vetor2)
{
    if ((vetor1 == NULL || vetor2 == NULL) || (vetor1->pqtde != vetor2->pqtde))
        return false;
    else
    {
        for (int counter = 0; (counter < (vetor1->pqtde - 1)) || (counter < (vetor2->pqtde - 1)); counter++)
        {
            if (vetor1->pvet[counter] != vetor2->pvet[counter])
                return false;
        }
        return true;
    }
}


int somaVet()
{
    typedef int 
    int tam;
    scanf("%d", );
}

int main(int argc, char const *argv[])
{
    vetor_t* teste = (vetor_t*) malloc(sizeof(vetor_t));
    vetor_t* teste2 = (vetor_t*) malloc(sizeof(vetor_t));
    inicVet(teste, 26);
    inicVet(teste2, 26);
    for (int alp = 0; alp < 20; alp++)
    {
        adicVet(teste, (char) 97 + alp);
        adicVet(teste2, (char) 97 + alp);
    }
    printf("%d\n", cmpVet(teste, teste2));
    adicVetOrd(teste, 'a');
    excluirVetOrd(teste, 'c');
    printVet(teste);
    desalocVet(teste);
    free(teste);
    return 0;
}
