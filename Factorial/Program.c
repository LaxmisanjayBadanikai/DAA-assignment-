#include<stdio.h>
#include<windows.h>

long long fact_rec(int n)
{
    if(n<=1)
        return 1;
    return n*fact_rec(n-1);
}

long long fact_iter(int n)
{
    long long f=1;
    for(int i=1;i<=n;i++)
        f*=i;
    return f;
}

int main()
{
    int n;
    LARGE_INTEGER start,end,freq;

    printf("Enter n: ");
    scanf("%d",&n);

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    long long r1=fact_rec(n);
    QueryPerformanceCounter(&end);

    double t1=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    QueryPerformanceCounter(&start);
    long long r2=fact_iter(n);
    QueryPerformanceCounter(&end);

    double t2=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    printf("\nRecursive Factorial: %lld",r1);
    printf("\nRecursive Time: %.0f ns",t1);

    printf("\n\nIterative Factorial: %lld",r2);
    printf("\nIterative Time: %.0f ns",t2);

    return 0;
}
