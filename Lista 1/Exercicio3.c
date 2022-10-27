#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int lines;
    int sum = 0;
    int newNum;
    scanf("%d", &lines);
    for (int line = 0; line < lines; line++)
    {
        scanf("%d", &newNum);
        sum += newNum;
    }
    printf("%d\n", sum);
    return 0;
    
}
