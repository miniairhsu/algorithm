#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

struct Node *root = NULL;
int node_height(struct Node* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balance_factor(struct Node* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node* llrotation(struct Node* p)
{
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = node_height(p);
    pl->height = node_height(pl);
    if(root == p)
        root = pl;
    return pl;
}

struct Node* lrrotation(struct Node* p)
{
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = node_height(pl);
    p->height = node_height(p);
    plr->height = node_height(plr); 
    if(root == p)
        root = plr;
    return plr;
}

struct Node* rrrotation(struct Node* p)
{
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = node_height(p);
    pr->height = node_height(pr);
    if(root == p)
        root = pr;
    return pr;
}

struct Node* rlrotation(struct Node* p)
{
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    pr->height = node_height(pr);
    p->height = node_height(p);
    prl->height = node_height(prl); 
    if(root == p)
        root = prl;
    return prl;
}
struct Node * insert_rec(struct Node* p, int key)
{
    struct Node* t;
    if(p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data) {
        p->lchild = insert_rec(p->lchild, key);
    } else if(key > p->data) {
        p->rchild = insert_rec(p->rchild, key);
    }
    p->height = node_height(p);
    if(balance_factor(p) == 2 && balance_factor(p->lchild) == 1) {
        printf("perform llrotation");
        return llrotation(p);
    }
    else if(balance_factor(p) == 2 && balance_factor(p->lchild) == -1)
        return lrrotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->rchild) == -1)
        return rrrotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->rchild) == 1)
        return rlrotation(p);
    return p;
}

void tcreate()
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
    root = insert_rec(root, 20);
    insert_rec(root, 10);
    insert_rec(root, 5);
    preorder(root);

    return 0;

}