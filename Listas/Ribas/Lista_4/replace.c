# include <stdio.h>

void replaceC(int counter, char * src, char to_replace, char for_it);

void replace(char * src, char to_replace, char for_it){
    replaceC(0, src, to_replace, for_it); 
}

int main(int argc, char const *argv[])
{
    char input[80];
    scanf("%s", input);
    replace(input, 'x', 'y');
    printf("%s\n", input);
    return 0;
}

void replaceC(int counter, char * src, char to_replace, char for_it){
    if (src[counter] == '\0' || src[counter] == '\n');
    else{
        if(src[counter] == to_replace){
            src[counter] = for_it;
        }
        replaceC(counter + 1, src, to_replace, for_it);   
    }
}
