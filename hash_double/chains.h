#ifndef CHAINS_H
#define CHAINS_H
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void insert_sort(struct Node** H, int x)
{
    struct Node *t, *q = NULL, *p = *H;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(*H == NULL)
        *H = t;
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == *H) {
            t->next = *H;
            *H = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}
#endif