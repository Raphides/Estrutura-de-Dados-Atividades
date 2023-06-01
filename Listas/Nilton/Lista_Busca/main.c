# include "csv_reader.h"
# include <stdio.h>

int main(int argc, char const *argv[])
{
    CSV* file = to_csv("Lista_Municipios_com_IBGE_Brasil_Versao_CSV.csv", ';', 1);
    printf("%c\n", fgetc(file->pkeys[0]));
    return 0;
}
