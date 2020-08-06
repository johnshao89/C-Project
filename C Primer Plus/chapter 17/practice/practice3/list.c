#include"list.h"
#include<stdlib.h>
/* Note: Now the List is a struct {Item entries[MaxSize]; int items}*/
void InitializeList(List *plist)
{
    plist->items=0;
}

bool ListIsEmpty(const List *plist)
{
    return plist->items==MAXSIZE;
}

unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

bool AddItem(Item item, List *plist)
{
    if(ListIsFull(plist))
    return false;
    else
    {
        plist->entries[plist->items++]=item;
        return true;
    }
    
}
void Traverse(const List*plist, void(*pfun)(Item item))
{
    int i=0;
    for(;i<plist->items;i++)
    (*pfun)(plist->entries[i]);
}
void EmptyTheList(List *plist)
{
    //nothing is malloc, so nothing to deallocate
    plist->items=0;
}
bool ListIsFull(const List *plist)
{
    return plist->items==MAXSIZE;
}