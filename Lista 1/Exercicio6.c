# include <stdio.h>
# include <stdbool.h>

int main(int argc, char const *argv[])
{
    int lines;
    int counter = 1;
    int Joao, Ze;
    for (scanf("%d", &lines); lines != 0; scanf("%d", &lines))
    {
        printf("Teste %d\n", counter);
        for (int i = 0; i < lines; i++)
        {
            scanf("%d %d", &Joao, &Ze);
            printf("%d\n", Joao - Ze);
        }
        printf("\n");
        counter++;
    }
    
    return 0;
}
