#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(j >= i)
        m->A[m->n * (i-1) + (i-2)*(i-1)/2 + j - i] = x;
}

void set_column_major(struct Matrix *m, int i, int j, int x)
{
    if(j >= i)
        m->A[j*(j-1)/2 + i-1] = x;
}

int get(struct Matrix m, int i, int j)
{
    if(j >= i)
        return m.A[m.n * (i-1) + (i-2)*(i-1)/2 + j - i];
    else 
        return 0;
}

int get_column_major(struct Matrix m, int i, int j)
{
     if(j >= i)
        return m.A[j*(j-1)/2 + i - 1];
    else 
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++){
        for(j = 1; j <= m.n; j++) {
            if(j >= i)
                printf("%d ", m.A[m.n * (i-1) + (i-2)*(i-1)/2 + j - i]);
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
            if(j >= i)
                printf("%d ", m.A[j*(j-1)/2 + i - 1]);
            else 
                printf("0 ");
        }
         printf("\r\n");
    }
}


int main()
{
    int *A, n, ch, x;
    int x;
    printf("Enter dimension:");
    scanf("%d",&n);
    A = (int *)malloc(n*sizeof(int));
    do {
        
        switch(ch) {
            //create
            case 1:
                for(i = 1; i <= n; i++) {
                    scanf("%d", &A[i-1]);
                }
                break;
            //get 
            case 2:
                printf("Enter indexs ");
                scanf("%d%d", &i, &j);
                if(i == j)
                    printf("%d\r\n", a[i-1]);
                else 
                    print("%d\r\n", 0);
                break;
            //set
            case 3:
                printf("Enter index ");
                scanf("%d%d%d", &i, &j, &x);
                if(i == j) A[i-1] = x;
                break;
            //display
            case 4:
                for(i = 1; i <= n; i++) {
                    for(j = 1; j <= n; j++){
                        if(i == j) printf("%d", a[i-1]);
                        else printf("%d",0);
                    }
                    printf("\r\n");
                }
                break;
        }
    }while();


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