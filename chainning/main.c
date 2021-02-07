#include <stdio.h>
#include <stdlib.h>
#include "chains.h"

int hash(int key)
{
    return key%10;
}

void insert(struct Node* H[], int key)
{
    int index = hash(key);
    insert_sort(&H[index], key);
}
int main()
{
    struct Node *HT[10];
    struct Node* temp;
    int i;
    for(int i = 0; i < 10; i++) {
        HT[i] = NULL;
    }
    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);
    temp = search(HT[hash(22)], 22);
    printf("data is %d\r\n", temp->data);
    /*for(int i = 0; i < 10; i++) {
        if(HT[i] != NULL) {
            while(HT[i] != NULL) {
                printf("data is %d \r\n", HT[i]->data);
                HT[i] = HT[i]->next;
            }
        }
    }*/
}