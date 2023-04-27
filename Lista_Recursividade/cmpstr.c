# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int cmpstr(char *frase1, char *frase2);
int cmpstr_aux(char *frase1, char *frase2, int pos);

int cmpstr_aux(char *frase1, char *frase2, int pos)
{
    if (frase1[pos] != frase2[pos])
        return 0;
    if (frase1[pos] == '\0')
        return 1;
    else
        cmpstr_aux(frase1, frase2, pos + 1);
}

int cmpstr(char *frase1, char *frase2)
{
    if ((frase1 == NULL && frase2 == NULL))
        return 0;
    else
        return cmpstr_aux(frase1, frase2, 0);
    
}

int main(int argc, char const *argv[])
{
    char* a = (char*) malloc(12 * sizeof(char));
    a[0] = 'a';
    a[1] = 'b';
    char* b = (char*) malloc(15 * sizeof(char));
    b[0] = 'a';
    printf("%d\n", cmpstr(a, b));
    b[1] = 'b';
    printf("%d\n", cmpstr(a, b));
    a = "";
    b = "";
    printf("%d\n", cmpstr(a, b));
    return 0;
}
