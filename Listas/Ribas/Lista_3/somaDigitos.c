# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int sum_each_value(char *values, int index, int sum);

int sum_of_digits(char *values){
    int sum = 0;
    return sum_each_value(values, 0, sum);
}

int sum_each_value(char *values, int index, int sum){
    if (values[index] == '\0')
    {
        return sum;
    }
    else if (strlen(values) > index)
    {
        sum += ((int) values[index]) - 48;
        sum_each_value(values, index + 1, sum);        
    }
    else
    {
        return sum;
    }
}
int main(int argc, char const *argv[])
{
    char input[12];
    scanf("%s", input);
    printf("%d\n", sum_of_digits(input));

    return 0;
}