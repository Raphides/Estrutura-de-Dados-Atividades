# include <stdio.h>
# include <string.h>

char oitavas[16] = "ABCDEFGHIJKLMNOP";
char quartas[8];
char semi[4];
char final[2];
unsigned char pontos[2];
char vencedor;

int calcular_fase(char * atual, char * proxima);


int main(int argc, char const *argv[])
{
    calcular_fase(oitavas, quartas);
    calcular_fase(quartas, semi);
    calcular_fase(semi, final);
    calcular_fase(final, &vencedor);
    printf("%c\n", vencedor);
    return 0;
}

int calcular_fase(char * atual, char * proxima){
    for (int i = 1; i < (sizeof(proxima) / sizeof(char)) + 1; i++)
    {
        scanf("%hhd %hhd", &pontos[0], &pontos[1]);
        if (pontos[0] > pontos[1])
        {
            strncat(proxima, &atual[2 * i - 2], 1);
        }
        else
        {
            strncat(proxima, &atual[2 * i - 1], 1);
        }
    }
        
}