# include <stdlib.h>
# include <stdio.h>

typedef char* pkey;

int csv_len_aux(FILE* stream, char separator)
{
    
}

unsigned int calculate_lines(FILE* stream)
{
    if (stream == NULL)
        return -1;
    else
    {
        char unit;
        unsigned int len = 0;
        while (1)
        {
            unit = fgetc(stream);
            if (unit == '\n')
                len += 1;
            else if (unit == EOF)
                return len;
        }
    }
        
}

pkey* csv_pkey(FILE* stream, char separator, int total_columns, int target_column)
{
    if (stream == NULL)
        return -1;
    unsigned int total_lines = calculate_lines(stream);
    pkey* result = (pkey*)malloc((total_lines + 1) * sizeof(pkey));
    unsigned int len = 0;
    for(int line = 0; line < total_lines;)
    {
        int column = 1;
        for (char unit = fgetc(stream); unit != EOF; unit = fgetc(stream))
        {
            if (column != target_column)
            {
                if (unit == ';')
                    column++;
                else if (unit == '\n')
                    break;
            } else
            {
                char*
            }
            
            
        }
        
        
        
        else if (column == target_column)
        {
            result[line] = ma
        }
        else if (unit == EOF)
            return len;
    }

        
}

int main(int argc, char const *argv[])
{
    FILE* dataset = fopen("Lista_Municipios_com_IBGE_Brasil_Versao_CSV.csv", "r");    
    
    
    fclose(dataset);
    return 0;
}
