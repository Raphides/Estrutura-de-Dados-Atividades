// Explicação do selection sort aqui: https://visualgo.net/en/sorting
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void selection_sort(int *unordered_sequence, int lenght){
    int minor_element_index;
    int tmp;
    int j;
    for (int i = 0; i < lenght; i++)
    {
        minor_element_index = i;
        for (j = i + 1; j < lenght; j++)
        {
            if (unordered_sequence[j] < unordered_sequence[minor_element_index])
            {
                minor_element_index = j;
            }
        }
        tmp = unordered_sequence[minor_element_index];
        unordered_sequence[minor_element_index] = unordered_sequence[i];
        unordered_sequence[i] = tmp;
        
    }
    
}


int main(int argc, char const *argv[])
{
    int *input = (int *) calloc(1001, sizeof(int));
    int counter;
    for (counter = 0; scanf("%d", &input[counter]) != EOF; counter++);
    selection_sort(input, counter);
    for (int i = 0; i < counter; i++){
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}


