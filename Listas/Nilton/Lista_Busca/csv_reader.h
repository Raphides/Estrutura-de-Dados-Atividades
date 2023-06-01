# ifndef CSV_reader
# define CSV_reader
# include <stdio.h>

typedef struct 
{
    char separator;
    int columns;
    char **head;
    int lines;
    FILE **pkeys;
    char * path;
    FILE* SRC;
} CSV;

CSV* to_csv(char* csv_path, char separator, int pkey);


# endif