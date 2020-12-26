#include <stdio.h>
//source, through, desitination
void toh(int n, int A, int B, int C)
{
    if(n > 0)
    {
        toh(n-1, A, C, B);
        printf("(%d, %d)\n\r", A, C);
        toh(n-1, B, A, C);
    }
}

int main()
{
    toh(3,1, 2, 3);
    return 0;
}