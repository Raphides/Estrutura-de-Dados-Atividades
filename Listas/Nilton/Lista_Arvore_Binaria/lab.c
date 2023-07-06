# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct 
{
    char *file_name;
    unsigned int columns, age_column, ts_column, line_column;
} Src_info_T;

Src_info_T pacient_registry;

typedef struct 
{
    unsigned int pkey, line;
} Pacient_T;

typedef struct 
{
    Binary_Node_T *right, *left;
    Pacient_T value;
}Binary_Node_T;

typedef struct 
{
    Binary_Node_T* root;
} Bin_tree_T;

Bin_tree_T* tree;

void ask_file_name(void)
{
    printf("\nInsira o nome do arquivo fonte: ");
    scanf("%s", pacient_registry.file_name);
}

void gather_pacient_info(void)
{
    FILE* src = fopen(pacient_registry.file_name, "r");
    unsigned int column = 0;
    char pkey_str[7];
    unsigned int age_col, ts_col;
    printf("\nInsira a posição da coluna Age: ");
    scanf("%d", &(pacient_registry.age_column));
    printf("\nInsira a posição da coluna Tumor Size: ");
    scanf("%d", &(pacient_registry.ts_column));
    fclose(src);
    
    //sprintf(pkey_str, "%d%d", age_col, ts_col);
    //sscanf(pkey_str, "%d", &(pacient_registry.pkey_column));

}

void load_data(void)
{
    tree = (Bin_tree_T*) malloc(sizeof(Bin_tree_T));
    char chr;
    unsigned int column;
    FILE* src = fopen(pacient_registry.file_name, "r");
    fgets(NULL, 1, src);
    for (unsigned int i = 2;1; i++)
    {
        column = 1;
        while ((chr = fgetc(src)) != EOF)
        {
            if (chr == ',')
                column += 1;
            else if (column == pacient_registry.age_column)
            {
                
            }
            else if (column == pacient_registry.ts_column)
            else if (chr == "\n")
            {
                break;
            }
            
        }
        
    }
    

    fclose(src); 
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        int option;
        printf("1. Carregar Arquivo de Dados\n2. Emitir Relatório\n3. Sair\nInsira o que quer: ");
        scanf("%d", &option);
        if (option == 1)
        {
            ask_file_name();
        }
        else if (option == 2)
        {
            ask_file_name();
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            printf("\nINSIRA UMA OPÇÃO VÁLIDA\n");
            continue;
        }
        
    }
    
    return 0;
}

