# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <math.h>
# include <string.h>

void vezes2(int* resultado, int a, int b, int contador)
{
    if (b != contador)
    {
        *resultado += a;
        vezes2(resultado, a, b, contador + 1); 
    }
}

int prod(int a, int b)
{
    int resultado = 0;
    vezes2(&resultado, a, b, 0);
    return resultado;
}

int prod2x_aux(int *resultado, int a, int b, int contador)
{
    if (contador != b)
    {
        *resultado = *resultado * a;
        prod2x_aux(resultado, a, b, contador + 1);
    }
}

int pot(int a, int b)
{
    if (b == 0)
        return 1;
    int resultado = a;
    prod2x_aux(&resultado, a, b, 0);
    return resultado;
}

int ePalindromo_aux(char *str, char* copy, int cont)
{
    if (cont != 0)
    {
        copy[strlen(str) - cont] = str[cont - 1];
        return ePalindromo_aux(str, copy, cont - 1);
    }
    else
    {
        if(strncmp(str, copy, strlen(str)) == 0)
            return 1;
        else
            return 0; 
    }
}

int ePalindromo(char *str)
{
    int cont = strlen(str);
    char *rcopy = (char *) malloc(cont + 1);
    return ePalindromo_aux(str, rcopy, cont);
    
}


int mdc(int maior, int menor)
{
    int resto = maior % menor;
    if (resto == 0)
        return menor;
    else
        mdc(maior / menor, resto);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", mdc(50, 3));
    return 0;
}

