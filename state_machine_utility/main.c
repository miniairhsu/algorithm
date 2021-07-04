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
#include "st_util.h"
pthread_t tid[2];
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
    /*while (1) {
        printf("Enter the first value:");
    }*/
}

void* cmd_exec(void* arg)
{
    //while (1) {
        //dequeue_task(&task_r1);
    //}
}

int main (int argc, char **argv)
{
    int err;
    int a = 8;
    int b = 9;
    struct sm_state start_state = CREATE_STATE("state_start", 1);
    init_st(&start_state);
    register_state_event(&start_state, 1, adder);
    register_state_event(&start_state, 2, suber);
    register_state_event(&start_state, 3, suber);
    struct sm_state second_state = CREATE_STATE("second_start", 2);
    register_state_event(&second_state, 1, adder);
    register_state_event(&second_state, 2, suber);
    register_state_event(&second_state, 3, suber);

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