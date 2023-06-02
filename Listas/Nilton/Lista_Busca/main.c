# include <stdio.h>
# include "csv_reader.h"

int main(int argc, char const *argv[])
{
    CSV* mycsv = to_csv("./teste.csv", ',', 0);
    if (mycsv == NULL)
        printf("putz\n");
    else
        printf("Colunas: %d\nLinhas: %d\n", mycsv->columns, mycsv->lines);
        char linha[50];
        FILE * csv_adress = mycsv->pkeys[0];
        printf("Raphael: %c%c%c\n", fgetc(csv_adress), fgetc(csv_adress), fgetc(csv_adress));
    unnassing_csv(mycsv);
    return 0;
}
