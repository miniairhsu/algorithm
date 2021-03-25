#include <stdio.h>
#include <stdlib.h>
void insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];
    while(i > 1 && temp > H[i/2]) {
        H[i] = H[i/2]; //swap with parent
        i = i/2; 
    }
    H[i] = temp;
}

//n is heap size, always delete root first
int delete(int A[], int n)
{
    int i, j, x, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1; j = i *2;
    while(j < n-1)
    {
        if(A[j+1] > A[j])
            j = j + 1;
        if(A[i] < A[j]) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else break;
    }
    return val;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35}; //0 is ignore
    //40 25 35 10 5 20 30 
    for(int i = 2; i < 8; i++) {
        insert(H, i);
    }

    delete(H, 7);
    for(int i = 1; i < 8; i++) {
        printf("%d ", H[i]);
    }
    printf("\r\n");
    delete(H, 5);
    for(int i = 1; i < 8; i++) {
        printf("%d ", H[i]);
    }
    printf("\r\n");
    return 0;
}