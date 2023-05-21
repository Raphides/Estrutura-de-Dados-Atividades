#include <stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* original = fopen("text.txt", "r");
    FILE* copia = fopen("copia.txt", "w");

    char char_original;
    while (1)
    {
        char_original = fgetc(original);
        if (char_original == EOF)
        {
            printf("FIM\n");
            break;
        }
        fputc(char_original, copia);
    }
    fclose(original);
    fclose(copia);

    return 0;
}
