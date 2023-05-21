# include <stdio.h>
# include <stdbool.h>


int main(int argc, char const *argv[])
{
    int valorPago[3]; int soma;
    scanf("%d %d %d %d", &valorPago[0], &valorPago[1], &valorPago[2], &soma);
    if (soma == valorPago[0] + valorPago[1] + valorPago[2])
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }
    return 0;
}
