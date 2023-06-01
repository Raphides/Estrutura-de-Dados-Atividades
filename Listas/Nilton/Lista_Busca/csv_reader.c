# include "csv_reader.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int __count_columns(CSV* csv)
{
    FILE* csvSRC = csv->SRC;
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
        return 1;
    }
    else
        return 0;
}


int __count_lines(CSV* csv)
{
    FILE* csvSRC = csv->SRC;
    char line[100];
    size_t count = -2;
    do
    {
        fgets(line, 100, csvSRC);
        count++;
    } while (line[0] != EOF);
    if (count > 0)
    {
        csv->lines = count;
        return 1;
    }
    else
        return 0;
}

int __get_pkey(CSV* csv, int pkey_column_index)
{
    FILE* csvSRC = csv->SRC;
    int column = 0;
    int line = 0;
    char chr;
    char lines[100];
    fgets(lines, 100, csvSRC);
    do
    {
        chr = fgetc(csvSRC);
        if (column == pkey_column_index)
            csv->pkeys[line] = csvSRC;
        if (csv->separator == chr)
            column++;
        else if (chr == '\n')
        {
            line++;
            column = 0;
        }
        else if (chr != EOF)
            break;
        
        
    } while (1);
    
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
        csv_file->SRC = fopen(csv_file->path, "r"); 
        if (__count_columns(csv_file) && __count_lines(csv_file))
        {
            csv_file->head = (char**) malloc(csv_file->columns * sizeof(char*));
            csv_file->pkeys = (FILE**) malloc(csv_file->lines * sizeof(FILE*));
            __get_pkey(csv_file, pkey);
        }
        else
        {
            free(csv_file);
            return NULL;
        }
        
    }
    
    
}