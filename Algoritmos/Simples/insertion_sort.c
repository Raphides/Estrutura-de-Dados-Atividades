// Mais explicações para o insertion sort podem ser achadas aqui: https://visualgo.net/en/sorting

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

void insertion_sort(int *unordered_sequence, int lenght){
    int to_order_element;
    int past_element_index;
    for (int to_order_index = 1; to_order_index <lenght; to_order_index++)
    {
        to_order_element = unordered_sequence[to_order_index];
        past_element_index = to_order_index - 1;
        while (past_element_index >= 0)
        {
            if (to_order_element > unordered_sequence[past_element_index])
            {
                break;
            }
            else
            {
                unordered_sequence[past_element_index + 1] = unordered_sequence[past_element_index];
                unordered_sequence[past_element_index] = to_order_element;
            }
            past_element_index--;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int *input = (int *) calloc(50001, sizeof(int));
    int counter;
    for (counter = 0; scanf("%d", &input[counter]) != EOF; counter++);
    insertion_sort(input, counter);
    for (int i = 0; i < counter; i++){
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}
