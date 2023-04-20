# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef int t_elemento;

typedef struct
{
    int tamanho;
    int lotacao;
    t_elemento* msg;
} vetor;

int main(int argc, char const *argv[])
{

    vetor vetor1 = {1, 1, "ola"};
    strcpy(vetor1.msg, "rapa");
    printf("%s\n", vetor1.msg);
    return 0;
}



