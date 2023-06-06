# ifndef CSV_READER
# define CSV_READER
# include <stdio.h>

typedef struct 
{
    // basic info

    char separator;
    int columns;
    int lines;
    char * path;

    // public addresses

    char **head;
    char **pkeys;
} CSV;

CSV* to_csv(char* csv_path, char separator, int pkey);

int unnassing_csv(CSV* csv);

# endif
