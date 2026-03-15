#include<stdio.h>
#include<windows.h>

void toh(int n,char s,char d,char a)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",s,d);
        return;
    }

    toh(n-1,s,a,d);
    printf("Move disk %d from %c to %c\n",n,s,d);
    toh(n-1,a,d,s);
}

int main()
{
    int n;
    LARGE_INTEGER start,end,freq;

    printf("Enter number of disks: ");
    scanf("%d",&n);

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);
    toh(n,'A','C','B');
    QueryPerformanceCounter(&end);

    double t=(double)(end.QuadPart-start.QuadPart)*1000000000/freq.QuadPart;

    printf("\nRunning Time: %.0f ns\n",t);

    return 0;
}
