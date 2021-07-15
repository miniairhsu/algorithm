#include "queue_util.h"

char* get_queue_name(int queue_id)
{
    switch(queue_id) {
        case 1 :
            return QUEUE1;
        case 2 :
            return QUEUE2;
        case 3: 
            return QUEUE3;
        case 4: 
            return QUEUE4;
        default:
            break;
    }
    return QUEUE1;
}

void register_queue(int queue_id, struct task_runner *task_r)
{
    key_t key;
    int msgid;
    memset(task_r, 0, sizeof(struct task_runner));
    key = ftok(get_queue_name(queue_id), GETQUEUE_ID(queue_id));
    task_r->msg_id = msgget(key, 0666 | IPC_CREAT);
}

int check_queue(struct task_runner* task_r) 
{
    struct msqid_ds buf;
    int num_messages;
    msgctl(task_r->msg_id, IPC_STAT, &buf);
    return buf.msg_qnum;
}

void enqueue_task(struct task_runner *task_r, void (*fn)(void*, void*), void* arg1, void* arg2)
{
    task_r->queue_i.fn = fn;
    task_r->queue_i.arg1 = arg1;
    task_r->queue_i.arg2 = arg2;
    task_r->queue_i.info = 4;
    int ret;
    if((ret = msgsnd(task_r->msg_id, &task_r->queue_i, sizeof(task_r->queue_i), 0)) != 0)
        printf("enqueue fail %d %d\r\n", ret, task_r->msg_id); 
}

void dequeue_task(struct task_runner* task_r)
{
        msgrcv(task_r->msg_id, &task_r->queue_i, sizeof(task_r->queue_i), 0, 0);
        task_r->queue_i.fn(task_r->queue_i.arg1, task_r->queue_i.arg2);
}

void kill_queue(struct task_runner *task_r) 
{
    if (msgctl(task_r->msg_id, IPC_RMID, NULL) == -1) {
        printf("kill queue error\r\n");
    }
    printf("message queue: done sending messages.\n");
}

   