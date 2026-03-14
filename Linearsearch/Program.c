#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int linear_search(int a[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n = 100000;
    int *a = (int*)malloc(n * sizeof(int));
    int i, key, pos;

    LARGE_INTEGER start, end, freq;

    for(i = 0; i < n; i++)
        a[i] = i + 1;

    key = n;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    pos = linear_search(a, n, key);

    QueryPerformanceCounter(&end);

    double time = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;

    if(pos != -1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found\n");

    printf("Execution Time = %.0f ns\n", time);

    free(a);
    return 0;
}
