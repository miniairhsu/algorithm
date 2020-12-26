#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node
{
    char data;
    struct Node* next;
} *top= NULL;


void display()
{
    int i;
    struct Node* p;
    p = top;
    while(p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void push(char x)
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

char pop() 
{
    struct Node* t;
    char x = -1;
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

int isBalance(char* exp)
{
    int i;
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')') {
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top == NULL)
        return 1;
    else 
        return 0;
}

int isBalance2(char* exp)
{
     int i;
     char x;
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == NULL)
                return 0;
            x = pop();
            if(x == '(' && exp[i] != ')') return 0;
            if(x == '[' && exp[i] != ']') return 0;
            if(x == '{' && exp[i] != '}') return 0;
        }
    }
    if(top == NULL)
        return 1;
    else 
        return 0;
}

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char * inToPost(char* infix)
{
    char *postfix;
    int i=0, j = 0;
    int len = strlen(infix);
    postfix = (char *)malloc((len+1) * sizeof(char));
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if(pre(infix[i]) > pre(top->data)) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

char * inToPost2(char* infix)
{
    char *postfix;
    int i=0, j = 0;
    int len = strlen(infix);
    postfix = (char *)malloc((len+1) * sizeof(char));
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if(outPrecedence(infix[i]) > inPrecedence(top->data)) {
                push(infix[i++]);
            } else if(outPrecedence(infix[i]) == inPrecedence(top->data)) {
                pop();
            } else {
                postfix[j++] = pop();
                
            }
        }
    }
    while(top != NULL) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
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
    char* exp = "[((a+b)*(c-d))]";
    //printf("%d\r\n", isBalance2(exp));
    char *infix = "a+b*c-d/e";
    push('#'); //prevent empty stack for inToPost
    char *postfix = inToPost2(infix);
    printf("%s\r\n", postfix);
    /*push(10);
    push(20);
    push(30);
    display();
    printf("%d\n", pop());
    display();*/
    return 0;
}