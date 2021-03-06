/*
 * server.c: Server program
 *           to demonstrate interprocess commnuication
 *           with POSIX message queues
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include "queue_util.h"
pthread_t tid[2];
struct task_runner task_s1; 
struct task_runner task_r1; 
void adder(void* a, void* b)
{
    printf("a1 + b1 = %d\r\n", *(int *)a + *(int *)b);
}

void suber(void* a, void* b)
{
    printf("a1 - b1 = %d\r\n", *(int *)a - *(int *)b);
}

void* cmd_scan(void* arg) 
{
    int a, b, c;
    while (1) {
        printf("Enter the first value:");
        scanf("%d %d %d", &a, &b, &c);
        if( a == 1 ) {
            enqueue_task(&task_s1, adder, (void *)&b, (void *)&c);
        } else if( a == 2 ) {
            enqueue_task(&task_s1, suber, (void *)&b, (void *)&c);
        } else {
            enqueue_task(&task_s1, adder, (void *)&b, (void *)&c);
            enqueue_task(&task_s1, suber, (void *)&b, (void *)&c);
        }
    }
}

void* cmd_exec(void* arg)
{
    while (1) {
        dequeue_task(&task_r1);
    }
}

int main (int argc, char **argv)
{
    int err;
    register_queue(1, &task_s1);
    register_queue(1, &task_r1);
    int a = 8;
    int b = 9;
    enqueue_task(&task_s1, adder, (void *)&a, (void *)&b);
    enqueue_task(&task_s1, suber, (void *)&a, (void *)&b);
    dequeue_task(&task_r1);
    dequeue_task(&task_r1);
    err = pthread_create(&(tid[0]), NULL, &cmd_scan, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    else {
        printf("\n Thread created successfully\n");
    }

    err = pthread_create(&(tid[1]), NULL, &cmd_exec, NULL);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    else {
        printf("\n Thread created successfully\n");
    }
    while (1) {
        
    }
    return 0;
}