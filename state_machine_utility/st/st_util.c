#include "st_util.h"


void init_st(struct sm_state* sm, void (*func)(void*, void*))
{
    sm->events = (struct event_list*)malloc(sizeof(struct event_list));
    sm->events->event = 0;
    sm->func = func;
    sm->events->handler = NULL;
    sm->events->next_event = NULL;
}

void dequeue_st_func(struct st_container* st_c) 
{
    dequeue_task(&st_c->sm_task);
}

struct event_list* match_state_event(struct sm_state* sm, sm_event event)
{
    int ret = 0;
    struct event_list* temp = sm->events;
    while(temp != NULL) {
        if(event == temp->event) {
            break;
        }
        temp = temp->next_event;
    }
    return temp;
}

void register_state_event(struct sm_state* sm, sm_event event, void (*handler) (void*, void*))
{
    struct event_list* temp;
    struct event_list* head = sm->events;
    if (head == NULL) {
        head = (struct event_list *)malloc(sizeof(struct event_list));
        head->event = event;
        head->handler = handler;
        head->next_event = NULL;
        return;
    } 
    while(head->next_event != NULL) {
        printf("event=%d\r\n", head->event);
        head = head->next_event;
    }
    temp = (struct event_list *)malloc(sizeof(struct event_list));
    temp->event = event;
    temp->handler = handler;
    temp->next_event = NULL;
    head->next_event = temp;
    head = head->next_event;
    printf("register event=%d\r\n", head->event);
    return;
}

void init_sc(struct st_container* st_c) 
{
    if(st_c == NULL) {
        st_c = (struct st_container *)malloc(sizeof(struct st_container));
    }
    st_c->sm_sts = (struct sm_state **)calloc(st_c->max_st, sizeof(struct sm_state*));
}

void register_state_container(struct st_container* st_c, struct sm_state* sm)
{
    int i = 0;
    if (st_c != NULL) {
        while(st_c->sm_sts[i] != NULL) {
            i++;
        } 
        if (i >= st_c->max_st) {
            printf("no of states overflow\r\n");
            return;
        }
        st_c->sm_sts[i] = sm;
    }
}

void init_sm(struct st_container* st_c, struct sm_state* init_state, int queue_id)
{
    st_c->curr_state = init_state;
    register_queue(queue_id, &st_c->sm_task);
}

void post_event(struct st_container* st_c, sm_event event)
{
    int i = 0;
    while(st_c->sm_sts[i] != NULL && i < st_c->max_st) {
        st_c->sm_sts[i]->current_event = event;
        i++;
    }
}

void set_state(struct sm_state* sm_st, struct sm_state* sm_st_next)
{
    //sm_st->next_state = sm_st_next;
}

struct sm_state* match_state(struct st_container* st_c, int st_id) 
{
    int i = 0;
    while(st_c->sm_sts[i] != NULL && i < st_c->max_st) {
        if (st_c->sm_sts[i]->st_id == st_id) {
            break;
        }
        i++;
    }
    return st_c->sm_sts[i];
}

void run_sm(struct st_container* st_c, void* arg1, void* arg2)
{
    printf("current_state id %d\r\n", st_c->curr_state->st_id);
    struct event_list* current_list = match_state_event(st_c->curr_state, st_c->curr_state->current_event);
    current_list->handler(arg1, arg2);
    //enque state machine specific function 
    enqueue_task(&st_c->sm_task, st_c->curr_state->func, arg1, arg2);

    //state transition
    st_c->curr_state = match_state(st_c, *(int *)arg1); //arg1 is returned next state id
    printf("next_state id %d\r\n", st_c->curr_state->st_id);
}

   