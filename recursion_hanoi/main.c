#include <stdio.h>
//source, through, desitination
void toh(int n, int A, int B, int C)
{
    if(n > 0)
    {
        toh(n-1, A, C, B); //top 2 to B 
        printf("(%d, %d)\n\r", A, C); //move buttom from A to C
        toh(n-1, B, A, C); //move top 2 from B to C 
    }
}

int main()
{
    toh(2,1, 2, 3);
    return 0;
}