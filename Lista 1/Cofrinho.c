# include <stdio.h>
# include <stdbool.h>

int main(int argc, char const *argv[])
{
    int lines;
    int counter = 1;
    int Joao, Ze;
    int difference = 0;
    for (scanf("%d", &lines); lines != 0; scanf("%d", &lines))
    {
        difference = 0;
        printf("Teste %d\n", counter);
        for (int i = 0; i < lines; i++)
        {
            scanf("%d %d", &Joao, &Ze);
            difference += Joao - Ze;
            printf("%d\n", difference);
        }
        printf("\n");
        counter++;
    }
    
    return 0;
}
