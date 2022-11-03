# include <stdio.h>

int main(int argc, char const *argv[])
{
    int input;
    int counter = 0;
    while (scanf("%d", &input) > 0)
    {
        counter++;
    }
    printf("%d\n", counter);
    
    return 0;
}