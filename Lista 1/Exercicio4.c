#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rounds, betoWinSum = 0, aliceWinSum = 0, result;
    int betoVictory = 1, aliceVictory = 0;
    for (scanf("%d", &rounds); rounds != 0 ;scanf("%d", &rounds))
    {
        for (int i = 0; i < rounds; i++)
        {
            scanf("%d", &result);
            if (result == aliceVictory)
            {
                aliceWinSum++;
            } else
            {
                betoWinSum++;
            }
        }
        printf("\nAlice ganhou %d e Beto ganhou %d\n", aliceWinSum, betoWinSum);
        aliceWinSum = 0; betoWinSum = 0;
    }
    return 0;
}
