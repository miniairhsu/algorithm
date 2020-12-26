#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int A[], int n)
{
    int i, j, flag = 0;
    for(i = 0; i < n-1; i++) { //pass
        flag = 0;
        for(j = 0; j < n - i -1; j++) //compare
        {
            if(A[j] > A[j+1]) {
                flag = 1;
                swap(&A[j], &A[j+1]);
            }
        }
        if(flag == 0) break; //no swap. already sorted
    }
}
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}; //0 is ignore
    int n =10;
    bubble(A, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\r\n");
}