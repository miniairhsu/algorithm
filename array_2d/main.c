#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j;
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1, 3,5,7}};//3rows, 4colums all in stack

    int *B[3]; //3rows in stack 
    int **C;
    for(i = 0;i < 3;i++) {
        for(j = 0; j < 4;j++) {
            printf("%d\r\n", A[i][j]);
        }
        printf("\r\n");
    }
    B[0] = (int *)malloc(4*sizeof(int)); //create column in heap
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));
    B[3] = (int *)malloc(4*sizeof(int));
    for(i = 0;i < 3;i++) {
        for(j = 0; j < 4;j++) {
            printf("%d\r\n", B[i][j]);
        }
        printf("\r\n");
    }


    C = (int **)malloc(3*sizeof(int *));
    C[0] = (int *)malloc(4*sizeof(int));
    C[1] = (int *)malloc(4*sizeof(int));
    C[2] = (int *)malloc(4*sizeof(int));
    C[3] = (int *)malloc(4*sizeof(int));
        B[0] = (int *)malloc(4*sizeof(int)); //create column in heap
    B[1] = (int *)malloc(4*sizeof(int));
    B[2] = (int *)malloc(4*sizeof(int));
    B[3] = (int *)malloc(4*sizeof(int));
    for(i = 0;i < 3;i++) {
        for(j = 0; j < 4;j++) {
            printf("%d\r\n", C[i][j]);
        }
        printf("\r\n");
    }

    return 0;
}