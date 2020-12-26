#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 10;
    int *q;
    q = (int *)malloc(10 * sizeof(int));
    for(int i = 0; i < 5; i++)
        printf("%d\r\n", p[i]);
    for(int i = 0; i < 5; i++)
        q[i] = p[i];
    free(p);
    p = q; //p contains q address
    q = NULL; //q points to NULL
    for(int i = 0; i < 5; i++)
        printf("%d\r\n", p[i]);
    return 0;
}