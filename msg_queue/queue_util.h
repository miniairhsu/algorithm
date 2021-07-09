#ifndef QUEUE_UTIL_H
#define QUEUE_UTIL_H

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define QUEUE_ID 65
#define QUEUE_NUM 4
#define GETQUEUE_ID(queue_id) (queue_id - 1 + QUEUE_ID)
#define QUEUE1 "main.exe"
#define QUEUE2 "queue2"
#define QUEUE3 "queue3"
#define QUEUE4 "queue4"
struct queue_item {
    char *arg1;
    char *arg2;
    void (*fn)(void*, void*);
    int info;
};

struct task_runner {
    int msg_id; 
    struct queue_item queue_i;
};

#define TASK_RUNNER_NAME(name, queue_id) (name##queue_id) 
 
//init task_runner with msg_id
char* get_queue_name(int queue_id);
void register_queue(int queue_id, struct task_runner *task_r);
int check_queue(struct task_runner* task_r);
void enqueue_task(struct task_runner *task_r, void (*fn)(void*, void*), void* arg1, void* arg2);
void dequeue_task(struct task_runner* task_r);
void kill_queue(struct task_runner *task_r);


#endif 