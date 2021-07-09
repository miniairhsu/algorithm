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
struct task_runner sm_task;
struct st_container st_container1;
void adder(void* a, void* b)
{
    *(int *)a = 2;
    printf("return event %d\r\n", *(int *)a);
}

void suber(void* a, void* b)
{
    *(int *)a = 1;
    printf("return event %d\r\n", *(int *)a);
}

void func_st1(void* a, void* b)
{
    printf("state1");
}

void func_st2(void* a, void* b)
{
    printf("state2");
}


void* cmd_scan(void* arg) 
{
    int a, b, c;
    while (1) {
        //printf("Enter the first value:");
        //dequeue_st_func((struct st_container *)arg);
    }
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
    int a;
    int b;
    struct sm_state start_state = CREATE_STATE("state_start", 1);
    init_st(&start_state, func_st1);
    register_state_event(&start_state, 1, adder);
    register_state_event(&start_state, 2, suber);
    register_state_event(&start_state, 3, suber);
    struct sm_state second_state = CREATE_STATE("second_start", 2);
    init_st(&second_state, func_st2);
    register_state_event(&second_state, 1, suber);
    register_state_event(&second_state, 2, suber);
    register_state_event(&second_state, 3, suber);
    struct st_container st_container1 = CREATE_STATE_CONTAINER("STATE1", 1, 5, sm_task);
    init_sc(&st_container1);
    register_state_container(&st_container1, &start_state);
    register_state_container(&st_container1, &second_state);
    init_sm(&st_container1, &start_state, 1);
    post_event(&st_container1, 1);
    run_sm(&st_container1, (void *)&a, (void *)&b);
    run_sm(&st_container1, (void *)&a, (void *)&b);
    run_sm(&st_container1, (void *)&a, (void *)&b);
    dequeue_st_func(&st_container1);
    dequeue_st_func(&st_container1);
    dequeue_st_func(&st_container1);     
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