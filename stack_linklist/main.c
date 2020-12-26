#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node* next;
} *top= NULL;


void display()
{
    int i;
    struct Node* p;
    p = top;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void push(int x)
{
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() 
{
    struct Node* t;
    int x;
    if(top == NULL)
        printf("stack is empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}


/*int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top - index + 1 < 0)
        printf("Invalid index \n");
    x = st.s[st.top - index + 1];
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int stackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}*/
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("%d\n", pop());
    display();
    return 0;
}