/* 
ET

Neste problema você receberá diversas strings de no máximo 30 caracteres, quando você identificar a string marte deverá imprimir o nome do seu colega que veio deste planeta, caso não aconteça nenhuma ocorrência de marte, você deverá imprimir none.

A entrada possui um único caso de teste terminando em EOF.
Exemplo de Entrada:

Brasil
marte
europa
venus

Exemplo de Saída:

Leonardo Cicero Marciano */
# include <stdio.h>
# include <string.h> 

int main(int argc, char const *argv[])
{
    char word[30];
    char marte[30] = "marte";
    do
    {
        if(scanf("%s", word) == EOF){
            break;
        }
    } while (strncmp(word, marte, 6) != 0);
    if (strncmp(word, marte, 6) == 0)
    {
        printf("Leonardo Cicero Marciano\n");
    }
    else {
        printf("none\n");
    }
    return 0;
}
