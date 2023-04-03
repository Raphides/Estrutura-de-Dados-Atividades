# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* file;
    char* text = (char *) calloc(100, sizeof(char));
    file = fopen("example.txt", "r");
    /*
    r - modo de leitura/read
    w - modo de escrita/reescrita/write
    a - modo de adição de texto / append
    
    */
    // ler arquivos.
    fgets(text, 100, file);
    printf("%s\n", text);
    fclose(file);
    free(text);

    // redefinir texto do arquivo.
    file = fopen("example.txt", "w");
    fprintf(file, "Escrevi esse texto.");
    fclose(file);
    text = (char *) calloc(100, sizeof(char));
    file = fopen("example.txt", "r");
    fgets(text, 100, file);
    printf("%s\n", text);
    fclose(file);
    free(text);

    // adicionar texto
    file = fopen("example.txt", "a");
    fprintf(file, " Adicionei esse texto.");
    fclose(file);
    text = (char *) calloc(100, sizeof(char));
    file = fopen("example.txt", "r");
    fgets(text, 100, file);
    printf("%s\n", text);
    fclose(file);
    free(text);

    return 0;
}
