#include "list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
}
bool ListIsEmpty(const List *plist)
{
    return plist->head==NULL;
}
unsigned int ListItemCount(const List *plist)
{
    Node *head;
    unsigned int count=0;
    head = plist->head;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    return count;

}
bool AddItem(Item item, List *plist)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node==NULL)
    {
        fprintf(stderr,"Can not allocate memory!\n");
        return false;
    }
    new_node->item = item;
    new_node->next = NULL;
    Node* search = plist->head;
    if(ListIsEmpty(plist))
        plist->head = plist->end = new_node;
    else
    {
        while(search->next!=NULL)
        {
            search = search->next;
        }
        search->next = new_node;
        plist->end = new_node;
    }
    return true;
    
}
void Traverse(const List*plist, void(*pfun)(Item item))
{
    Node *scan;
    scan = plist->head;
    while(scan!=NULL)
    {
        (*pfun)(scan->item);
        scan = scan->next;
    }
}
void EmptyTheList(List *plist)
{
    Node *psave;
    while(plist->head!=NULL)
    {
        psave = plist->head->next;
        free(plist->head);
        plist->head = psave;
    }
}
bool ListIsFull(const List *plist)
{
    Node*new_node;
    return (new_node=(Node*)malloc(sizeof(Node)))==NULL;
}