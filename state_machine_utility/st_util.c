#include "st_util.h"


void init_st(struct sm_state* sm)
{
    sm->events = (struct event_list*)malloc(sizeof(struct event_list));
    sm->events->event = 0;
    sm->events->handler = NULL;
    sm->events->next_event = NULL;
}

int match_state_event(struct sm_state* sm, sm_event event)
{
    int ret = 0;
    struct event_list* temp = sm->events;
    while(temp != NULL) {
        if(event == temp->event) {
            ret = 1;
            break;
        }
        temp = temp->next_event;
    }
    return ret;
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

void init_sm(struct sm_controller* sm_ctrl, struct sm_state* init_state, int queue_id)
{
    sm_ctrl->curr_state = init_state;
    register_queue(queue_id, &sm_ctrl->sm_task);
}


void set_state(struct sm_state* sm_st, struct sm_state* sm_st_next)
{
    //sm_st->next_state = sm_st_next;
}

void run_sm(struct sm_controller* sm_ctrl)
{
    //enqueue_task(&sm_ctrl->sm_task, sm_ctrl->curr_state->handler, sm_ctrl->curr_state->state_data1, sm_ctrl->curr_state->state_data2);
    //struct sm_state* temp;
    //state transitiion
    //sm_ctrl->curr_state = sm_ctrl->next_state;
    //sm_ctrl->next_state = sm_ctrl->next_state->next_state;
}

   