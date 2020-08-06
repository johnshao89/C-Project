#include "queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InitializeQueue(Queue *pq)
{
    pq->head=pq->rear=NULL;
    pq->items=0;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items==0;
}

bool QueueIsFull(const Queue *pq)
{
    return pq->items==MAXQUEUE;
}

unsigned int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
    if(QueueIsFull(pq))
    return false;
    else
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        if(new_node==NULL)
        {
            fprintf(stderr, "Can not allocate memeory for new item.\n");
            return false;
        }
        new_node->next=NULL;
        new_node->item = item;
        if(QueueIsEmpty(pq))
            pq->head = pq->rear = new_node;
        else
        {
            pq->rear->next = new_node;
            pq->rear = new_node;
        }
        pq->items++;
        return true;
    }
}

bool DeQueue(Item *pi, Queue *pq) //pi is the pointer that used to save the address of to-be-removed item
{
    Node * temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        fprintf(stderr, "Can not allocate memory to remove queue.\n");
        return false;
    }
    *pi = pq->head->item;
    temp = pq->head;
    pq->head = temp->next;
    free(temp);
    pq->items--;
    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Node *psave;
    psave = pq->head;
    while(psave !=NULL)
    {
        pq->items--;
        psave = pq->head;
        free(pq->head);
        pq->head = psave->next;
        psave=psave->next;

    }
}
