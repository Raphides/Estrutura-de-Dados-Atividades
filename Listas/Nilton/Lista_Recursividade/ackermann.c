# include <stdio.h>
# include <stdlib.h>

int ackermann_aux(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann_aux(m - 1, 1);
    else    
        return ackermann_aux(m - 1, ackermann_aux(m, n - 1));
}

/**
 * @brief Função de Ackerman
 * 
 * @param m 
 * @param n 
 * @return Retorna -1 caso as entradas sejam inválidas.
 */
int AckermannRecursivo(int m, int n)
{
    if (m < 0 || n < 0)
        return -1;
    else
        return ackermann_aux(m, n);
}

int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("Resultado: %d\n", AckermannRecursivo(m,n));
    return 0;
}
