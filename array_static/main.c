#include <stdio.h>
#include <stdlib.h>
double e(int x, int n)
{
    static double p=1,f=1;
    double r;
    if(n == 0)
        return 1;
    r = e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

int main()
{
    int A[10] = {2,4,6,8,10};
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 10;
    for(int i = 0; i < 5; i++)
        printf("%d\r\n", A[i]);
    for(int i = 0; i < 5; i++)
        printf("%d\r\n", p[i]);
    return 0;
}