# include <stdio.h>
# include <stdlib.h>

int mdc(int numero1, int numero2);

int mmc(int numero1, int numero2);

int mdc_aux(int maior, int menor)
{
    int resto = maior % menor;
    if (resto == 0)
        return menor;
    else
        return mdc_aux(menor, resto);
}

int mdc(int numero1, int numero2)
{
    numero1 = abs(numero1);
    numero2 = abs(numero2);
    if (numero1 == 0)
    {
        if (numero1 == 0 && numero2 == 0)
        {
            return -1;
        }
        return numero2;
    }
    else if (numero2 == 0)
        return numero1;
    else if (numero1 >= numero2)
        return mdc_aux(numero1, numero2);
    else
        return mdc_aux(numero2, numero1);
    
}

int mmc(int numero1, int numero2)
{
    if (numero1 < 0 || numero2 < 0)
        return -1;
    else
    {
        return ((numero1 * numero2) / mdc(numero1, numero2));  
    }
}



int main(int argc, char const *argv[])
{
    // checando a questão da prova de Matemática Discreta 2.
    for (int i = 1; i < 31; i +=2)
    {
        for (int j = 2; j < 31; j+=2)
        {
            if (mmc(j,i) == 60 & mdc(j,i) == 3)
                printf("%d / %d\n", i, j);
        }
    }
}
