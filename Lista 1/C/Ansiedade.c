# include <stdio.h>
# include <string.h>

int main(int argc, char const *argv[])
{
    int triagens = 0;
    char resposta[3];
    int counter;
    while (scanf("%s", resposta) != EOF)
    {
        counter = 0;
        if (strncmp(resposta, "sim", 3) == 0)
        {
            counter++;
        }
        for (int i = 1; i < 10; i++)
        {
            scanf("%s", resposta);
            if (strncmp(resposta, "sim", 3) == 0)
            {
                counter++;
            }
        }
        if (counter >= 2)
        {
            triagens++;
        }
    }
    printf("%d\n", triagens);
    return 0;
}
