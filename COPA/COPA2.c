# include <stdio.h>
# include <stdbool.h>

int main(int argc, char const *argv[])
{
    int caixa[3];
    int diametro;
    bool cabe = true;
    char resposta;
    scanf("%d %d %d %d", &diametro, &caixa[0], &caixa[1], &caixa[2]);
    for (int i = 0; i < 3; i++)
    {
        if(caixa[i] < diametro){
            cabe = false;
            break;
        }
    }
    
    if (cabe)
    {
        resposta = 'S';
    }
    else
    {
        resposta = 'N';
    }
    printf("%c\n", resposta);
    return 0;
}
