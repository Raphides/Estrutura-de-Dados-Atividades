# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>

typedef char * string_ls;

FILE* original;
FILE* copia;
int main(int argc, char const *argv[])
{
    original = fopen("POEMA.txt", "r");
    string_ls *palavras = (string_ls *) calloc(1000, sizeof(string_ls));
    char letter;
    int word_counter = -1;
    bool is_new_word = true;
    for (int i=0; 1; i++)
    {
        letter = fgetc(original);
        if (letter == EOF)
            break;
        if (isalnum(letter))
        {
            if (is_new_word)
            {
                word_counter++;
                palavras[word_counter] = (char *) calloc(1000, sizeof(char));
                i = 0;
                is_new_word = false;
            }
            palavras[word_counter][i] = letter;
        }
        else if (!isalnum(letter))
        {
            is_new_word = true;
            i--;
        }
        
    }
    word_counter++;
    copia = fopen("DICIO.txt", "w");
    bool is_duplicated;
    for (int j = 0; j < word_counter; j++)
    {
        char *palavra = palavras[j];
        is_duplicated = false;
        for (int k = 0; k < word_counter; j++)
        {
            int len_palavra = strlen(palavra); 
            if (k != j && (strncmp(palavra, palavras[k], len_palavra) == true))
            {
                is_duplicated = true;
                break;
            }            
        }
        if (is_duplicated)
            fputc(',', copia);
        else
            fputs(palavra, copia);
    }
    
    
    return 0;
}
