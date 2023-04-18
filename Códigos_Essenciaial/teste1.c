# include <stdlib.h>
# include <stdio.h>

int main(int argc, char const *argv[])
{
    float *opa = malloc(10 * sizeof(float));
    float *haha = calloc(10, sizeof(float));
    printf("%p\n%p\n", opa, haha);
    free(opa);
    free(haha);    
    return 0;
}
