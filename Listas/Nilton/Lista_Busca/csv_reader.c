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
    char line[100];
    size_t count = -1;
    while (fgets(line, 100, csvSRC) != NULL)
    {        
        count += 1;
    }
    if (count >= 0)
    {
        csv->lines = count;
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
    int column = 0, line = 0;
    char chr, lines[100];
    fgets(lines, 99, csvSRC);
    do
    {
        chr = fgetc(csvSRC);
        if (csv->separator == chr)
            column++;
        else if (chr == '\n')
        {
            line++;
            column = 0;
        }
        else if (chr == EOF)
            break;
        else if (column == pkey_column_index)
            csv->pkeys[line] = csvSRC;
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
            csv_file->pkeys = (FILE**) malloc((csv_file->lines+1) * sizeof(FILE*));
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

int unnassing_csv(CSV* csv)
{
    if (csv == NULL)
        return 0;
    free(csv->head);
    free(csv->pkeys);
    free(csv);
    return 1;
}
