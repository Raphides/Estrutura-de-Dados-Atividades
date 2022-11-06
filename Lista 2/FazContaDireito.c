# include <stdio.h>

int faz_conta_direito(int parcelas, char op);

int faz_conta_direito(int parcelas, char op)
{
    int total;
    int value;
    scanf("%d", &total);
    if (op == '+')
    {
        for (int i = 0; i < parcelas - 1; i++)
        {
            scanf("%d", &value);
            total += value;
        }
    } else
    {
        for (int i = 0; i < parcelas - 1; i++)
        {
            scanf("%d", &value);
            total -= value;
        }
    }
    return total; 
}