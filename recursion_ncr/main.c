#include <stdio.h>

int fact(int n)
{
    if(n==0) 
        return 1;
    return fact(n-1)*n;

}

//n!/(r! * (n-r)!)
int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n-r);
    return num/den;
}

int NCR(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    return NCR(n-1, r-1) + NCR(n-1, r);
}

int main()
{
    printf("%d\r\n", NCR(5,2));
    return 0;
}