# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void reverse(char* dest, char *src);
void reverseC(char* dest, char *src, int len, int index);

int main(int argc, char const *argv[])
{
    char *input = calloc(500, sizeof(char));
    scanf("%s", input);
    input = (char *) realloc(input, strlen(input) * sizeof(char));
    char *result = (char *) calloc(strlen(input), sizeof(char));
    reverse(result, input);
    printf("%s\n", result);
    return 0;
}


void reverse(char* dest, char *src){
    int len = strlen(src); 
    reverseC(dest, src, len, len - 1);
}

void reverseC(char* dest, char *src, int len, int index){
    if (index == -1);
    else
    {
        if (src[index] == '\0'/*|| src[len] == '\n'*/);
        else
        {
            dest[len - index - 1] = src[index];
        }
        reverseC(dest, src, len, index - 1);
    }
    
}