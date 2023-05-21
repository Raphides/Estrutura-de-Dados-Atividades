# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int binary_search(int *ordered_sequence, int lenght, int search_value){
    int start = 0;
    int end = lenght - 1;
    while (start != end - 1){
        if (search_value < ordered_sequence[(start + end) / 2])
        {
            end = (start + end) / 2;
        }
        else if (search_value > ordered_sequence[(start + end) / 2])
        {
            start = (start + end) / 2;
        }
        else
        {
            return (start + end) / 2;
            
        }
    }

    if (search_value > ordered_sequence[start] && search_value < ordered_sequence[end])
    {
        return end;
    }
    else if (search_value > ordered_sequence[start] && search_value > ordered_sequence[end])
    {
        return end + 1;
    }
    else
    {
        return (search_value == ordered_sequence[lenght - 1]) ? lenght - 1 : start;
    }
}


int main(int argc, char const *argv[])
{
    int nn;
    int nm;
    scanf("%d %d", &nn, &nm);
    int *m = (int *) calloc(nm, sizeof(int));
    int *n = (int *) calloc(nn, sizeof(int));
    for (int i = 0; i < nn; i++)
    {
        scanf("%d", &n[i]);
    }
    for (int j = 0; j < nm; j++)
    {
        scanf("%d", &m[j]);
        printf("%d\n", binary_search(n, nn, m[j]));
    }
    
    return 0;
}
