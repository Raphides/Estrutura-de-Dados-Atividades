# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char *message;
char *allXs;
char input;
int counter_x = 0;
int counter_message = 0;

char *movex(void);


int main(int argc, char const *argv[])
{
    message = (char *) calloc(100, sizeof(char));
    allXs = (char *) calloc(100, sizeof(char));
    printf("%s\n", movex());
    return 0;
}

char *movex(void){
    if (scanf("%c", &input) != EOF && input != '\n')
    {
        if (input == 'x')
        {
            allXs[counter_x] = input;
            counter_x++;
        }
        else {
            message[counter_message] = input;
            counter_message++;
        }
        movex();  
    } else {
        message = (char *) realloc(message, sizeof(char) * counter_message);
        allXs = (char *) realloc(allXs, sizeof(char) * counter_x);
        return strcat(message, allXs);
    }
}