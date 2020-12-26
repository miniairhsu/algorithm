#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Enter size ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for(i = st.top;i >= 0; i--) {
        printf("%d ", st.s[i]);
    }
    printf("\r\n");
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size - 1)
        printf("stack overflow\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack* st) 
{
    int x = -1;
    if(st->top == -1) 
        printf("stack underflow\r\n");
    else {
        x = st->s[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
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
}
int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    display(st);
    printf("%d\n", peek(st,1));
    display(st);
    return 0;
}