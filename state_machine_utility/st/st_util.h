#ifndef ST_UTIL_H
#define ST_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include "queue_util.h"

#define STATE_MAX 10

typedef int sm_event;

struct event_list 
{
    sm_event event;
    void (*handler) (void*, void*);
    struct event_list* next_event;
};

struct sm_state
{
    char* name;
    int current_event;
    int st_id;
    struct event_list* events;
    void (*func) (void*,void*);
    void* state_data1;
    void* state_data2;
};

struct st_container
{
    char* name;
    int sm_id;
    int max_st;
    struct task_runner* sm_task;
    struct sm_state** sm_sts;
    struct sm_state* curr_state;
};

struct sm_controller
{
    struct sm_state* curr_state;
    struct sm_state* next_state;
    struct task_runner sm_task;
};

#define CREATE_STATE(_name, _id) \
            {.name=_name, \
             .st_id=_id \
            }
#define CREATE_STATE_CONTAINER(_name, _id, _max_st, _sm_task) \
            { \
                .name=_name, \
                .sm_id=_id, \
                .max_st=_max_st, \
                .sm_task=_sm_task \
            }
void init_st(struct sm_state* sm, void (*func)(void*, void*));
void dequeue_st_func(struct task_runner* sm_task);
void register_state_event(struct sm_state* sm, sm_event event, void (*handler) (void*, void*));
struct event_list* match_state_event(struct sm_state* sm, sm_event event);
void register_state_container(struct st_container* st_c, struct sm_state* sm);
struct sm_state* match_state(struct st_container* st_c, int st_id);
void init_sm(struct st_container* st_c, struct sm_state* init_state, int queue_id);
void post_event(struct st_container* st_c, sm_event event);
void init_sc(struct st_container* st_c, char* name, int id, int max_st, struct task_runner* sm_task);
void run_sm(struct st_container* st_c, void* arg1, void* arg2);
void sm_task_execute(struct st_container* st_c);




#endif 