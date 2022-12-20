// explanation on https://visualgo.net/en/sorting
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

void bubble_sort(int *unorded_sequence, int lenght);

int main(int argc, char const *argv[])
{
    int *input = (int *) calloc(1001, sizeof(int));
    int counter;
    for (counter = 0; scanf("%d", &input[counter]) != EOF; counter++);
    bubble_sort(input, counter);
    for (int i = 0; i < counter; i++){
        printf("%d ", input[i]);
    }
    printf("\n");
    return 0;
}

void bubble_sort(int *unorded_sequence, int lenght){
    int iteration;
    bool changed_places;
    do
    {
        changed_places = false;
        for (iteration = 0; iteration < lenght - 1; iteration++)
        {
            if (unorded_sequence[iteration] > unorded_sequence[iteration + 1])
            {
                int tmp = unorded_sequence[iteration];
                unorded_sequence[iteration] = unorded_sequence[iteration + 1];
                unorded_sequence[iteration + 1] = tmp;
                changed_places = true; 
            }
        }
    } while (changed_places);
    
}
