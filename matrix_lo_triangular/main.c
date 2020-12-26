#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(i >= j)
        m->A[i*(i-1)/2 + j-1] = x;
}

void set_column_major(struct Matrix *m, int i, int j, int x)
{
    if(i >= j)
        m->A[m->n * (j-1) + (j-2)*(j-1)/2 + i - j] = x;
}

int get(struct Matrix m, int i, int j)
{
    if(i >= j)
        return m.A[i*(i-1)/2 + j - 1];
    else 
        return 0;
}

int get_column_major(struct Matrix m, int i, int j)
{
     if(i >= j)
        return m.A[m.n * (j-1) + (j-2)*(j-1)/2 + i - j];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++) {
            if(i >= j)
                printf("%d ", m.A[i*(i-1)/2 + j -1]);
            else 
                printf("0 ");
        }
         printf("\r\n");
    }
}

void Display_column_major(struct Matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++) {
            if(i >= j)
                printf("%d ", m.A[m.n * (j-1) + (j-2)*(j-1)/2 + i - j]);
            else 
                printf("0 ");
        }
         printf("\r\n");
    }
}


int main()
{
    struct Matrix m;
    int x;
    printf("Enter dimension:");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    printf("enter all elements:");
    for(int i = 1; i <= m.n; i++) {
        for(int j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set_column_major(&m, i, j, x);
        }
    }
    printf("\r\n");
    Display_column_major(m);

    return 0;
}