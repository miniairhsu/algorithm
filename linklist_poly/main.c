#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
}*poly = NULL;

void create()
{
    int num,i;
    struct Node* t, *last;
    printf("Number of terms ");
    scanf("%d", &num);
    printf("Enter each term coeff and exp \r\n");
    for( i = 0; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if(poly == NULL) {
            poly = last = t;
       } else {
           last->next = t;
           last = t;
       }
    }
}

void display(struct Node* p)
{
    while(p != NULL) {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
}

long eval(struct Node* p, int x)
{
    long val;
    while(p) {
        val += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main()
{
    create();
    display(poly);
    printf("%ld\r\n", eval(poly, 1));
    return 0;
}