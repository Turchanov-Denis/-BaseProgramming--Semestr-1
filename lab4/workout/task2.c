#include <stdio.h>
#include <string.h>

#define N 7
int isPrime(int n)
{
    if (n > 1)
    {
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;

        return 1;
    }
    else
        return 0;
}

int main()
{
    int store[100] = {0};

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if ((isPrime(i + j)) && !(store[i]) && (!(store[j]) && (i != j)))
            {
                printf("(%d,%d)\n", i, j);
                store[i] = 1;
                store[j] = 1;
            }
        }
    }
}