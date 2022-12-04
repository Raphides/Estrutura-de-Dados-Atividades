# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char *message;
char *allXs;
char chr;
char *input;
int counter = 0;
int counter_x = 0;
int counter_message = 0;

char *movex(void);


int main(int argc, char const *argv[])
{
    message = (char *) calloc(100, sizeof(char));
    allXs = (char *) calloc(100, sizeof(char));
    input = (char *) calloc(100, sizeof(char));
    scanf("%[^\n]s", input);
    printf("%s\n", movex());
    return 0;
}

char *movex(void){
    chr = input[counter];
    if (chr != '\0')
    {
        if (chr == 'x')
        {
            allXs[counter_x] = chr;
            counter_x++;
        }
        else {
            message[counter_message] = chr;
            counter_message++;
        }
        counter++;
        movex();  
    } else {
        free(input);
        message = (char *) realloc(message, sizeof(char) * counter_message);
        allXs = (char *) realloc(allXs, sizeof(char) * counter_x);
        return strcat(message, allXs);
    }
}