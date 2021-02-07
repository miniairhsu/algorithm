#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define I 65536
int cost[][8] ={
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I}, 
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};
int near[8] = {I,I,I,I,I,I,I,I};
int t[2][6];
 

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
    int i,j,k,u,v,n=7, min = I;
    //find min cost edge
    for(i = 1; i <= n ;i++) {
        for(j = i; j <= n; j++) {
            if(cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = 0;
    near[v] = 0;

    //init near array
    for(i = 0; i <= n; i++) {
        if(near[i] != 0) {
            if(cost[i][u] < cost[i][v]) {
                near[i] =u;
            } else {
                near[i] = v;
            }
        }
    }

    //repeat
    for(i = 1; i < n-1; i++) {
        min = I;
        for(j = 1; j <= n; j++) {
            if(near[j] != 0 && cost[j][near[j]] < min) {
                k = j;
                min = cost[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0; //included, don't check again
        //update near array
        for(j = 1; j <= n; j++) {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    for(i = 0; i <= n-1; i++) {
        printf("%d,%d ", t[0][i], t[1][i]);
    }

    return 0;
}