#include<stdio.h>
#include<stdlib.h>
#include"list.h"
static void CopyToNode(Item item, Node *pnode);

void InitializeList(List* plist)
{
    *plist = NULL;
}

bool ListIsEmpty(const List*plist)
{
    return (*plist==NULL? true:false);
}

bool ListIsFull(const List *plist)
{
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    return (new==NULL?true:false);
}

unsigned int ListItemCount(const List*plist)
{
    unsigned int count=0;
    Node*search=*plist;
    while(search!=NULL)
    {
        count++;
        search = search->next;
    }
    return count;
}

bool AddItem(Item item, List *plist)
{
    Node *new_node; //make a new node to hold item;
    Node *scan = *plist;
    new_node = (Node *)malloc(sizeof(Node));
    if(new_node==NULL)
    return false;
    CopyToNode(item,new_node);
    new_node->next = NULL;
    if(scan==NULL)
    *plist = new_node;
    else
    {
        while(scan->next!=NULL)
        scan = scan->next;
        scan->next = new_node;
    }
    return true;
}

void Traverse(const List *plist, void(*pfun)(Item item))
{
    Node *pnode=*plist;
    while(pnode!=NULL)
    {
        pfun(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List *plist)
{
    Node *psave;
    while(*plist!=NULL)
    {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}