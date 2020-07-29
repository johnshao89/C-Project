#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdbool.h>
typedef struct customer{
                long arrive;
                int processtime;
    }Item;
#define MAXQUEUE 10
typedef struct node{
    Item item;
    struct node *next;
}Node;
typedef struct queue{
    Node* front;
    Node * rear;
    int items;
}Queue;
void InitializeQueue(Queue *pq);
bool QueueIsEmpty(Queue *pq);
bool QueueIsFull(Queue *pq);
int QueueItemCount(Queue *pq);
bool EnQueue(Item item, Queue *pq);
bool DeQueue(Item *item, Queue *pq);
void EmptyTheQueue(Queue *pq);
#endif