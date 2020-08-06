#ifndef _QUEUE_H_
#define _QUEUE_H_
#define MAXQUEUE 10
#include<stdbool.h>
typedef struct customer{
    long arrive;
    int processtime;
}Item;

typedef struct node{
    Item item;
    struct node *next;
}Node;

typedef struct queue{
    Node *head;
    Node *rear;
    int items;
}Queue;

void InitializeQueue(Queue *pq);
bool QueueIsEmpty(const Queue *pq);
bool QueueIsFull(const Queue *pq);
unsigned int QueueItemCount(const Queue *pq);
bool EnQueue(Item item, Queue *pq);
bool DeQueue(Item *pi, Queue *pq);
void EmptyTheQueue(Queue *pq);

#endif