#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "queue.h"
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsEmpty(Queue *pq)
{
    return pq->items==0;
}

bool QueueIsFull(Queue *pq)
{
    return pq->items==MAXQUEUE;
}

int QueueItemCount(Queue *pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue *pq) //add node at the end
{
    Node * new_node = (Node *)malloc(sizeof(Node));
    if(new_node==NULL)
    {
        fprintf(stderr,"Memory allocation falied\n");
        return false;
    }
    if(QueueIsFull(pq))
    {
        fprintf(stderr,"The Queue is full.\n");
        return false;
    }
    new_node->next=NULL;
    if(QueueIsEmpty(pq))
        pq->front = new_node;
    else
        pq->rear->next = new_node;
    pq->rear = new_node;
    CopyToNode(item,new_node);
    pq->items++;
    return true;   
}

bool DeQueue(Item *pitem, Queue *pq)
{
    if(QueueIsEmpty(pq))
    return false;
    CopyToItem(pq->front,pitem);
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp ==NULL)
    {
        fprintf(stderr, "Can not allocate memory!\n");
        exit(1);
    }

    temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    pq->items--;
    return true;
}

void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DeQueue(&dummy,pq);
}
static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}
static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}