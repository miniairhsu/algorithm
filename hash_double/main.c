#include <stdio.h>
#include <stdlib.h>
#include "chains.h"

#define SIZE 10
#define PRIME 7 

int hash(int key)
{
    return key%SIZE;
}

int primeHash(int key)
{
    return PRIME - (key % PRIME);
}

int doubleHash(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[(hash(index) + i * primeHash(index)) % SIZE] != 0) {
        i++;
    }
    return (index + i * primeHash(index)) % SIZE;
}
void insert(int H[], int key)
{
    int index = hash(key);
    if(H[index] != 0) {
        index = doubleHash(H, key);
    }
    H[index] = key;
}

int search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[(hash(index) + i * primeHash(index))%SIZE] != key) {
        i++;
        if(H[(hash(index) + i * primeHash(index))%SIZE] == 0)
            return -1;
    }
    return (hash(index) + i * primeHash(index)) % SIZE;
}

int main()
{
    int HT[10] = {0};
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    printf("key found at %d\r\n", search(HT, 25));
}