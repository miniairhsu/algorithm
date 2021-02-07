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

int isEmpty()
{
    return front == NULL;
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

void bfs(int g[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while(!isEmpty()) {
        i = dequeue();
        for(j = 1; j < n; j++) {
            if(g[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

}

void dfs(int g[][7], int start, int n)
{
    static int visited[7] = {0};
    int j;
    if(visited[start] == 0) {
        printf("%d ", start);
        visited[start] = 1;
        for(j = 1; j < n; j++) {
            if(g[start][j] == 1 && visited[j] == 0) {
                dfs(g, j, n);
            }
        }
    }
}

int main()
{
    int g[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
    dfs(g, 1, 7);
    return 0;
}