#include <stdio.h>

double e(int x, int n)
{
    static double p=1,f=1;
    double r;
    if(n == 0)
        return 1;
    r = e(x,n-1);
    p=p*x; //x^n 
    f=f*n; //n!
    return r+p/f;
}

int main()
{
    printf("%f\r\n", e(2,3));
    return 0;
}