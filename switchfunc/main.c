#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
This program provides a possible solution for producer-consumer problem using mutex and semaphore.
I have used 5 producers and 5 consumers to demonstrate the solution. You can always play with these values.
*/

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void (*g_print) (char * str);
int g_count = 0;
void print1(char* str)
{
    sem_wait(&empty);
    printf("print1 %s g_count %d\r\n", str, g_count);
    g_count++;
    sleep(1);
    sem_post(&empty);
    
}

void print2(char* str)
{
    sem_wait(&empty);
    printf("print2 %s g_count %d\r\n", str, g_count);
    g_count--;
    sleep(1);
    sem_post(&empty);
}

void print_main() 
{
    while(1) {
        if (g_print != NULL) {
            g_print("hello");
        } else {
            printf("Print NULL\r\n");
        }
    }
}

void print_cancel()
{
    pthread_mutex_lock(&mutex);
    if(g_print != NULL)
        g_print = NULL;
    pthread_mutex_unlock(&mutex);
}

void switch_print(void  (*print_func)(char*)) 
{   
    pthread_mutex_lock(&mutex);
    g_print = print_func;
    pthread_mutex_unlock(&mutex);
}

void keep_switch()
{
    static int i = 0;
    while(1) {
        if(i == 0) {
            switch_print(print1);
            i++;
        } else if (i == 1) {
            switch_print(print2);
            i--;
        } else {
            //print_cancel();
            //i = 0;
        }
    }
}



void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0, 1);
    pthread_t p_t;
    pthread_t s_t;
    g_print = print1;
    pthread_create(&p_t, NULL, (void *)print_main, (void *)1);
    pthread_create(&s_t, NULL, (void *)keep_switch, (void *)2);
    pthread_join(p_t, NULL);
    pthread_join(s_t, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    //print_main();
    //switch_print(print2);
    //print_main(); 
    /*pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 5; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);*/

    return 0;
    
}