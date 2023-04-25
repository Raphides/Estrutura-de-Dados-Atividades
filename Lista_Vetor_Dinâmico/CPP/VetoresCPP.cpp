typedef char elemento;

int *CriaVetInt(int n_elementos)
{
    if (n_elementos <=0)
        return nullptr;
    return new int[n_elementos];
}

float *criaVetFloat(int n_elementos)
{
    if (n_elementos <=0)
        return nullptr;
    return new float[n_elementos];
}

typedef struct Vetor
{
    int ptamax;
    int pqtde;
    elemento* pvet;
} vetor_t;


int adicVet(vetor_t* vetor, elemento novo_elemento)
{
    if ((vetor->ptamax == vetor->pqtde) || vetor == nullptr)
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




