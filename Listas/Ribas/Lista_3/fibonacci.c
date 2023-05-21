# include <stdlib.h>
//# include <stdio.h>

long int seq[85];

long int fib(int now, int final);

long int fibonacci (int n){
    seq[0] = 0;
    seq[1] = 1;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fib(2, n);   
    }
}

long int fib(int now, int final){
    if (now > final)
    {
        return seq[now - 1];
    }
    else
    {
        seq[now] = seq[now - 1] + seq[now - 2];
        fib(now + 1, final);
    }

}

/* int main(int argc, char const *argv[])
{
    int example;
    scanf("%d", &example);
    printf("%li\n", fibonacci(example));
    return 0;
} */