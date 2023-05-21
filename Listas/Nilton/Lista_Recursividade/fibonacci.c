# include <stdio.h>
int fibonnaci(int n);
int fib(int n);

int fib(int n)
{
    switch (n)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    default:
        return fib(n - 1) + fib(n - 2);
        break;
    }
}

int fibonacci(int n)
{
    if (n < 0)
        return -1;
    else
        fib(n);
}

int main(int argc, char const *argv[])
{
    printf("%d\n", fib(8));
    return 0;
}
