# include <stdio.h>

int main(int argc, char const *argv[])
{
    int restaurants;
    int bestRestaurant[2];
    int presentRestaurant[2];
    int counter = 1;
    while (scanf("%d", &restaurants) != EOF)
    {
        bestRestaurant[0] = 0;
        bestRestaurant[1] = 0;
        for (int i = 0; i < restaurants; i++)
        {
            scanf("%d %d", &presentRestaurant[0], &presentRestaurant[1]);
            if (presentRestaurant[1] > bestRestaurant[1])
            {
                bestRestaurant[0] = presentRestaurant[0];
                bestRestaurant[1] = presentRestaurant[1];
            }
            else if (presentRestaurant[1] == bestRestaurant[1])
            {
                if (bestRestaurant[0] == 0 || presentRestaurant[0] < bestRestaurant[0])
                {
                    bestRestaurant[0] = presentRestaurant[0];
                }       
            }
        }
        printf("Dia %d\n%d\n\n", counter, bestRestaurant[0]);
        counter++;        
    }
    return 0;
}
