# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int n_times;
int jogos;

void leitura(void);
char *getTime(int index);
void setTime(int index, char nome[], int pontos);
int empates();

struct placarTimes
{
    char nome[200][10];
    int pontos[200];
};
struct placarTimes placar;


void setTime(int index, char nome[], int pontos){
    strcpy(placar.nome[index], nome);
    placar.pontos[index] = pontos;
}
char *getTime(int index){
    return placar.nome[index] + ' ' + placar.pontos[index];
}

int main(int argc, char const *argv[])
{
    leitura();
    return 0;
}

void leitura(void){
    scanf("%d", &n_times);
    if (n_times == 0)
    {
        exit(EXIT_SUCCESS);
    }
    for (int k = 0; k < 200; k++)
    {
        for (int l = 0; l < 10; l++)
        {
            strcpy(placar.nome[k], "\0");      
        }
        placar.pontos[k] = 0;
    }    
    scanf("%d", &jogos);
    for (int i = 0; i < n_times; i++)
    {
        scanf("%s %d", placar.nome[i], &placar.pontos[i]);
    }
    printf("%d\n", empates());
    leitura();
}

int empates(){
    int total = 0;
    for (int j = 0; j < sizeof(placar.pontos) / sizeof(int); j++)
    {
        total += placar.pontos[j] % 3;
    }
    return total / 2;
}