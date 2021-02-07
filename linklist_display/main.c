#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node* t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node* t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for(i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node* p)
{
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void display_rec(struct Node* p) 
{
    if(p != NULL) {
        printf("%d ", p->data);
        display(p->next);
    } else {
        printf("\r\n");
    }
}

int count(struct Node *p)
{
    int l = 0;
    while(p) {
        l++;
        p = p ->next;
    }
    return l;
}

int count_rec(struct Node* p)
{
    if(p == NULL)
        return 0;
    else {
        return count_rec(p->next) + 1;
    } 
}

int max(struct Node* p)
{
    int max = -65534;
    while(p) {
        if(p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int max_rec(struct Node* p)
{
    int x = 0;
    if(p == NULL)
        return -65536;
    else {
        x = max_rec(p->next);
        if(x > p->data)
            return x;
        else 
            return p->data;
    }
}

int sum(struct Node* p)
{
    int sum = 0;
    while(p != NULL) {
        sum += p->data;
        p = p->next; 
    }
    return sum;
}

int sum_rec(struct Node* p) 
{
    if(p == NULL)
        return 0;
    else
        return sum_rec(p->next) + p->data;
}

struct Node* search_linear(struct Node* p, int key)
{
    while(p != NULL) {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node* search_linear_fr(struct Node* p, int key)
{
    struct Node* q;
     while(p != NULL) {
        if(key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node* search_rec(struct Node* p, int key)
{
    if(p == NULL)
        return NULL;
    if(p->data == key)
        return p;
    return search_rec(p->next, key);
}

void insert(struct Node* p, int index, int x)
{
    struct Node* t;
    if(index < 0 || index > count(p)) 
        return; 
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0) {
        t->next = first;
        first = t;
    } else {
        for(int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insert_sort(struct Node* p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = t;
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p == first) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int isSorted(struct Node* p)
{
    int x = -65536;
    while( p != NULL) {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

int delete(struct Node* p, int index)
{
    struct Node *q;
    int x  = 1;
    if(index < 1 || index > count(p))
        return -1;
    else {
        if(index == 1) {
            q = first;
            x = first->data;
            first = first->next;
            free(q);
            return x;
        } else {
            for(int i = 0; i < index - 1; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            free(p);
            return x;
        }
    }   
}

void duplicate_remove(struct Node* p)
{
    struct Node *q = p->next;
    while(q != NULL) {
        if(p->data != q->data) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse_array(struct Node* p)
{
    int *a, i = 0;
    struct Node* q = p;
    a = (int *)malloc(sizeof(int) * count(p));
    while(q != NULL) {
         [i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL) {
        q->data = a[i];
        q = q->next;
        i--;
    }
}

void reverse_slide(struct Node* p)
{
    struct Node *q = NULL, *r = NULL;
    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_rec(struct Node* q, struct Node* p)
{
    if(p != NULL) {
        reverse_rec(p, p->next);
        p->next = q; //in returning p is q, p is previous node
    } else {
        first = q;
    }
}

void concat(struct Node *p, struct Node* q)
{
    third = p;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node* p, struct Node* q)
{
    struct Node* last;
    if(p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q) {
         if(p->data < q->data) {
             last->next = p;
             p = p->next;
             last = last->next;
             last->next = NULL;
         } else {
             last->next = q;
             q = q->next;
             last = last->next;
             last->next = NULL;
         }
    }
    if(p) { 
        last->next = p;
    }
    if(q) {
        last->next = q;
    }
} 

int isLoop(struct Node* f)
{
    struct Node *p, *q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    }while(p && q && p != q);
    if(p == q) return 1;
    else return 0;
}

struct Node* find_middle(struct Node* f)
{
    struct Node *p, *q;
    p = q = f;
    while(q) {
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    return p;
}

void find_intersection(struct Node* f)
{
    return;
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 30, 35, 40, 50};
    int B[] = {5, 115, 137, 144, 152};
    struct Node* temp; 
    create(A, 5);
    create2(B, 5);
    /*display_rec(first);
    printf("Length is %d sum is %d max is %d\r\n", count_rec(first), sum_rec(first), max_rec(first));
    temp = search_linear_fr(first, 20);
    if(temp)
        printf("key is %d\r\n", temp->data);
    else 
        printf("key is not found\r\n");
    display_rec(first);
    insert(first, 2, 10);
    display_rec(first);*/
    /*insert_sort(first, 5);
    delete(first, 1);
    display_rec(first);
    printf("is sorted %d\r\n", isSorted(first));
    duplicate_remove(first);
    display_rec(first);
    reverse_rec(NULL, first);
    display_rec(first);*/
    //concat(first, second);
    
    /*merge(first, second);
    display(third);*/
    /*t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1; //loop
    printf("%d\r\n", isLoop(first));*/
    struct Node* middle = find_middle(first);
    printf("%d\r\n", middle->data);
    return 0;
}