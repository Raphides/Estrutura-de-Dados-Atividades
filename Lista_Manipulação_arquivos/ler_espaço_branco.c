#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_white_spaces(FILE* file)
{
    if (file == NULL)
        return -1;
    int counter = 0;
    for (char charac = fgetc(file); charac != EOF; charac = fgetc(file))
    {
        switch (charac)
        {
            case ((char) 32):
                counter++;
                break;
            case ('\n'):
                counter++;
                break;
        }
    }
    return counter;
    
}

int main(int argc, char const *argv[])
{
    FILE* arq = fopen("text.txt", "r");
    printf("%d\n", count_white_spaces(arq));
    return 0;
}
