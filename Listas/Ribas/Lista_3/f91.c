# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int f91(int num);

int main(){
    int input;
    while (true) {
        scanf(" %d", &input);
        printf("f91(%d) = %d\n", input, f91(input));
    }
}
int f91(int num) {
    if (num == 0) {
        exit(EXIT_SUCCESS);
    }
    else if (num >= 101) {
        return num - 10;
    }
    else {
        return 91;
    }
}
