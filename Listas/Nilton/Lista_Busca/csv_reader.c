# include "csv_reader.h"
# include <stdio.h>
# include <stdlib.h>

int __count_columns(CSV* csv)
{
    FILE* csvSRC = fopen(csv->path, "r");
    char chr;
    size_t count = 0;
    do
    {
        chr = fgetc(csvSRC);
        if (chr == csv->separator)
        {
            count++;
            continue;
        }
    } while (chr != '\n');
    if (count > 0)
    {
        csv->columns = count;
        fclose(csvSRC);
        return 1;
    }
    else
        fclose(csvSRC);
        return 0;
}


int __count_lines(CSV* csv)
{
    FILE* csvSRC = fopen(csv->path, "r");
    size_t count = -1;
    char chr;
    while (1)
    {       
        chr = fgetc(csvSRC);
        if (chr == EOF)
            break;
        else if (chr == '\n')
            count += 1;
    }
    if (count >= 0)
    {
        csv->lines = count + 1;
        fclose(csvSRC);
        return 1;
    }
    else
        fclose(csvSRC);
        return 0;
}

void __get_pkey(CSV* csv, int pkey_column_index)
{
    FILE* csvSRC = fopen(csv->path, "r");
    int column = 0, line = 0, char_counter = 0;
    char chr, lines[100];
    fgets(lines, 99, csvSRC);
    csv->pkeys[0] = (char*) malloc(100);
    do
    {
        chr = fgetc(csvSRC);
        if (csv->separator == chr)
        {
            column++;
        }
        else if (chr == '\n')
        {
            csv->pkeys[line] = (char*) realloc(csv->pkeys[line], char_counter + 1);
            line++;
            csv->pkeys[line] = (char*) malloc(100);
            column = 0;
            char_counter = 0;
        }
        else if (chr == EOF)
        {
            csv->pkeys[line] = (char*) realloc(csv->pkeys[line], char_counter + 1);
            break;
        }
        else if (column == pkey_column_index)
        {
            csv->pkeys[line][char_counter] = chr;
            char_counter++;
        }
    } while (1);
    fclose(csvSRC);
}


CSV* to_csv(char* csv_path, char separator, int pkey)
{
    if (csv_path == NULL)
        return NULL;
    else
    {
        CSV *csv_file = (CSV*) malloc(sizeof(CSV));
        csv_file->separator = separator;
        csv_file->path = csv_path;

        if (__count_columns(csv_file) && __count_lines(csv_file))
        {
            csv_file->head = (char**) malloc((csv_file->columns+1) * sizeof(char*));
            csv_file->pkeys = (char**) malloc((csv_file->lines+1) * sizeof(char*));
            __get_pkey(csv_file, pkey);
            return csv_file;
        }
        else
        {
            free(csv_file);
            return NULL;
        }   
    }
}

int __pkey_aux_search(CSV* csv,char* key)
{  
    
}

int csv_pkey_search(CSV* csv, char* key)
{
    if (key == NULL)
        return 0;
    else
        return __pkey_aux_search(csv,key);
}




int unnassing_csv(CSV* csv)
{
    if (csv == NULL)
        return 0;
    free(csv->head);
    for (int i = 0; i < csv->lines; i++)
    {
        free(csv->pkeys[i]);
    }
    free(csv->pkeys);
    free(csv);
    return 1;
}
