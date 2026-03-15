#include<stdio.h>
#include<windows.h>

int gcd_consecutive(int m,int n)
{
    int t = (m<n)?m:n;

    while(t>0)
    {
        if(m%t==0 && n%t==0)
            return t;
        t--;
    }
    return 1;
}

int main()
{
    int m,n,g;
    LARGE_INTEGER start,end,freq;

    printf("Enter two numbers: ");
    scanf("%d %d",&m,&n);

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    g = gcd_consecutive(m,n);
    QueryPerformanceCounter(&end);

    double t=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    printf("\nGCD = %d",g);
    printf("\nExecution Time = %.0f ns\n",t);

    return 0;
}
