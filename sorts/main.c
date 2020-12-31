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

void insertion(int A[], int n)
{
    int i, j, x;
    for(i = 1; i < n; i++) //passes
    {
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x) {//swap
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selection(int A[], int n)
{
    int i, j, k;
    for(i = 0; i < n -1; i++) {
        for(j=k=i; j < n; j++) {
            if(A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h)
{
    int pivot = A[l]; //low
    int i = l, j = h;
    do {
        do {
            i++;
        }while(A[i] <= pivot);

        do {
            j--;
        }while(A[j] > pivot);
        if( i < j ) swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[l], &A[j]); //move pivot to j
    return j;
}

void quicksort(int A[], int l, int h)
{
    int j;
    if(l < h) {
       j =  partition(A, l, h); 
       quicksort(A, l, j);
       quicksort(A, j+1, h);
    }
}

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid+1 ,k = l;
     printf("k is %d\r\n", k);
    int B[100] = {0};

    while(i <= mid && j <= h) {
        if(A[i] < A[j]) {
            B[k] = A[i];
            printf("B1[k] %d %d\r\n", k, B[k]);
            k += 1;
            i += 1;
        } else
        {
            B[k] = A[j];
            printf("B2[k] %d %d\r\n", k, B[k]);
            k += 1;
            j += 1;
        }
        
    }
    for(;i <= mid; i++) {
        B[k] = A[i];
        printf("B3[k] %d %d\r\n", k, B[k]);
        k = k+1;
    }
    for(;j <= h; j++) {
        B[k] = A[j];
        printf("B4[k] %d %d\r\n", k, B[k]);
        k = k + 1;
    }
    for(i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void merge_iterative(int A[], int n) 
{
    int p, l, h, mid, i;
    for(p = 2; p <= n; p = p*2) {
        for(i = 0; i + p - 1 <= n ; i = i + p) {
            l = i;
            h = i + p -1;
            mid = (l + h)/ 2;
            printf("l m h %d %d %d\r\n", l, mid, h);
            merge(A, l, mid, h);
            
        }
    }
    if(p / 2 < n)
        merge(A, 0, (p/2)-1, n);
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 13}; //0 is ignore
    //int A[] = {2, 4 , 5, 3};
    int n =10;
    merge_iterative(A, 11);
    //quicksort(A, 0, 10);
    for(int i = 0; i < 11; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\r\n");
}