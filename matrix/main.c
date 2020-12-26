#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(i == j)
        m->A[i-1] = x;
}

int get(struct Matrix m, int i, int j)
{
    if(i == j)
        return m.A[i-1];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++) {
            if(j == i)
                printf("%d ", m.A[i-1]);
            else 
                printf("0 ");
        }
         printf("\r\n");
    }
}


int main()
{
    struct Matrix m;
    m.n = 4;
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 12);
    printf("%d\r\n", get(m, 2, 2));
    Display(m);

    return 0;
}