# include <stdio.h>

int processa_empates(int t, int n);

int main(int argc, char const *argv[])
{
    int t, n;
    while (scanf("%d %d", &t, &n) == 2 &&t != 0)
    {
        printf("%d\n",processa_empates(t, n));
    }
    
    return 0;
}

int processa_empates(int t, int n){
    int s = 0;
    for (int i = 0; i < t; i++)
    {
        int aux;
        char lxo[100000];
        scanf(" %s %d", lxo, &aux);
        s += aux;
    }
    return 3 * n - s;
    
}