#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}*first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last=first;
    for(i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        //t->next = last->next;
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int length(struct Node *p) {
    int len = 0;
    while(p != NULL) {
        len++;
        p=p->next;
    }
    return len;
}

/*void insert(struct Node* p , int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > length(Head)) {
        return;
    }
    if(index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(Head == NULL)  {
            Head = t;
            Head->next = Head;
        } else {
            while(p->next != Head) p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }

    } else {
        for(i = 0; i < index -1; i++) p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}*/

void display(struct Node *h)
{
    do {
        printf("%d ", h->data);
        h = h->next;
    }while(h != NULL);
    printf("\r\n");
}

/*void display_rec(struct Node *h)
{
    static int flag = 0;
    if(h != Head || flag == 0) {
        flag = 1;
        printf("%d ",h->data);
        display_rec(h->next);
    }
    flag = 0;
}*/

/*int delete(struct Node *p, int index) 
{
    struct Node *q;
    int i,x;
    if(index < 0 || index > length(p)) 
        return -1;
    if(index == 1) {
        while(p->next != Head) {
            p = p->next;
        }
        x = Head->data;
        if(p == Head) {
            free(Head);
            Head = NULL;
        } else {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    } else {
        for(i = 0; i < index-2;i++) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}*/

void insert(struct Node* p, int index, int x)
{
    struct Node* t;
    int i;
    if(index < 0 || index > length(p))
        return;
    if(index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for(i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        t->prev = p;
        t->next = p->next;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

int delete(struct Node* p, int index) 
{
    int i, x = -1;
    if(index < 1 || index > length(p))
        return -1;
    
    if(index == 1) {
        first = first->next;
        if(first) first->prev = NULL;
        x = p->data;
        free(p);
    } else {
        for(i = 0; i < index - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        free(p);
    }   
    return x;
}

void reverse(struct Node* p) 
{
    struct Node* temp;
    while(p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL) first = p;
    }
}


int main()
{
    
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    /*insert(first, 0, 10);
    delete(first, 2);*/
    reverse(first);
    display(first);
    printf("Length %d\r\n", length(first));
    return 0;
}