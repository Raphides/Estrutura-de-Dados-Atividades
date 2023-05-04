# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int mdc_aux(int a, int b)
{
    int resto = a % b;
    if (resto == 0)
        return abs(b);
    else
        return mdc_aux(b, resto);
    
}

int mdc(int a, int b)
{
    if (a == 0)
    {
        if (a == 0 && b == 0)
            return -1;
        else
            return b;
    }
    else if (b == 0)
        return a;
    else
    {
        if (abs(a) < abs(b))
            return mdc_aux(b, a);
        else
            return mdc_aux(a, b);  
    }
}

int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("Resultado: %d\n", mdc(m,n));
    return 0;
}