#include <stdio.h>
#include <windows.h>

int gcd_middle(int a, int b)
{
    int g = 1;
    int i = 2;

    while(i <= a && i <= b)
    {
        if(a % i == 0 && b % i == 0)
        {
            g = i;
        }
        i++;
    }
    return g;
}

int main()
{
    int a = 84, b = 36;
    int g;

    LARGE_INTEGER f, s, e;

    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&s);

    g = gcd_middle(a, b);

    QueryPerformanceCounter(&e);

    double t = (double)(e.QuadPart - s.QuadPart) * 1e9 / f.QuadPart;

    printf("Number 1 : %d\n", a);
    printf("Number 2 : %d\n", b);
    printf("GCD : %d\n", g);
    printf("Time : %.0lf ns\n", t);

    return 0;
}
