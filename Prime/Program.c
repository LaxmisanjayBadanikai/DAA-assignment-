#include<stdio.h>
#include<windows.h>

int isPrime(int n)
{
    if(n<2) return 0;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    LARGE_INTEGER start,end,freq;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    printf("Prime Numbers up to 1000:\n\n");

    for(int i=2;i<=1000;i++)
    {
        if(isPrime(i))
            printf("%d ",i);
    }

    QueryPerformanceCounter(&end);

    double t=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    printf("\n\nExecution Time: %.0f ns\n",t);

    return 0;
}
