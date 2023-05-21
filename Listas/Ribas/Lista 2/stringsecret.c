# include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int *var = 0;
    while (scanf("%p", var) != EOF) 
    {
        printf("%c", *var);
    }
    
    return 0;
}