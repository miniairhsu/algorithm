#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear = NULL;


void display()
{
    struct Node* p = front;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\r\n");
}

void enqueue(int x) 
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL) 
        printf("Queue is full\r\n");
    else {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* t;
    if(front == NULL)
        printf("Queue is empty \r\n");
    else {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    int *a = (int *)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) {
        a[i] = i;
    }
    int *b = a;
    free(b);
    for(int i = 0; i < 5; i++)
        printf("a %d\r\n", a[i]);
    return 0;
}