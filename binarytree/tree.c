#include "tree.h"

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (struct Node **)malloc(q->size * sizeof(struct Node*));
}

void enqueue(struct Queue *q, struct Node* x) 
{
    if((q->rear + 1) % q->size == q->front)
        printf("Queue is full\r\n");
    else {
        q->rear = (q->rear + 1) %q->size;
        q->Q[q->rear] = x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if(q->front == q->rear)
        printf("Queue is empty \r\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

void create_stack(struct stack *st, int size)
{
    st->top = -1;
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct stack *st, struct Node* x)
{
    if(st->top == st->size - 1)
        printf("stack overflow\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

struct Node * pop(struct stack* st) 
{
    struct Node * x = NULL;
    if(st->top == -1) 
        printf("stack underflow\r\n");
    else {
        x = st->s[st->top--];
    }
    return x;
}

int isEmptyStack(struct stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFullStack(struct stack st)
{
    return st.top == st.size - 1;
}
