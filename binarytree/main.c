#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

struct Node *root = NULL;
void createt()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while(!isEmpty(q)) {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node* p) 
{
    if(p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node* p) 
{
    if(p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node* p) 
{
    if(p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void preorder_i(struct Node* p)
{
    struct stack stk;
    create_stack(&stk, 100);
    while(p || !isEmptyStack(stk)) {
        if(p) {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void levelorder(struct Node* root)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);
    while(!isEmpty(q)) {
        root = dequeue(&q);
        if(root->lchild) {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild) {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

void inorder_i(struct Node* p)
{
    struct stack stk;
    create_stack(&stk, 100);
    while(p || !isEmptyStack(stk)) {
        if(p) {
            push(&stk, p);
            p = p->lchild;
        } else {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

int count(struct Node* root)
{
    if(root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(struct Node* root)
{
    int x = 0, y = 0;
    if(root == NULL)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if( x > y) return x + 1;
    else return y + 1;
}

int main()
{
    createt();

    inorder_i(root);
    printf("\r\n");
    postorder(root);
    levelorder(root);
    printf("count %d height %d\r\n", count(root), height(root));

    return 0;

}