#include<stdio.h>
#include<windows.h>

long long fib_rec(int n)
{
    if(n<=1)
        return n;
    return fib_rec(n-1)+fib_rec(n-2);
}

long long fib_dp(int n)
{
    long long a=0,b=1,c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return n?b:a;
}

int main()
{
    int n;
    LARGE_INTEGER start,end,freq;

    printf("Enter n: ");
    scanf("%d",&n);

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    long long r1=fib_rec(n);
    QueryPerformanceCounter(&end);

    double t1=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    QueryPerformanceCounter(&start);
    long long r2=fib_dp(n);
    QueryPerformanceCounter(&end);

    double t2=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    printf("\nRecursive Fibonacci: %lld",r1);
    printf("\nRecursive Time: %.0f ns",t1);

    printf("\n\nOptimized Fibonacci: %lld",r2);
    printf("\nOptimized Time: %.0f ns",t2);

    return 0;
}
