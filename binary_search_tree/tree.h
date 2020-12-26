#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct stack
{
    int size;
    int top;
    struct Node **s;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q, int size);
void enqueue(struct Queue *q, struct Node* x);
struct Node * dequeue(struct Queue *q);
int isEmpty(struct Queue q);
void create_stack(struct stack *st, int size);
void push(struct stack *st, struct Node* x);
struct Node * pop(struct stack* st);
int isEmptyStack(struct stack st);
int isFullStack(struct stack st);

#endif