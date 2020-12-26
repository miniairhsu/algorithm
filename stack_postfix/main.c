#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
    int x = -1;
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

int isEmpty(struct Node* st)
{
    if(st == NULL)
        return 1;
    return 0;
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
            if(isEmpty(top) || outPrecedence(infix[i]) > inPrecedence(top->data)) {
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

int eval(char* postfix)
{
    int i = 0;
    int x1, x2, r;
    for(i = 0; postfix[i] != '\0';i++) {
        if(isOperand(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
            case '+': r = x1 + x2; break;
            case '-': r = x1 - x2; break;
            case '*': r = x1 * x2; break;
            case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    printf("result is %d\r\n", eval(postfix));
    return 0;
}