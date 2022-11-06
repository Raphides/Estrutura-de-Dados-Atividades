# include <stdio.h>

int main(int argc, char const *argv[])
{
    int numOfPeople;
    int sum;
    scanf("%d", &numOfPeople);
    int total[2] = {0, 0};
    for (int i = 0; i < numOfPeople; i++)
    {
        scanf("%d", &total[1]);
        total[0] += total[1];
    }
    scanf("%d", &sum);
    if (sum == total[0])
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }
        
    return 0;
}
