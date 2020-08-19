#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void InitializeTheStack(Stack * ps)
{
    *ps = NULL;
}

bool StackIsEmpty(const Stack *ps)
{
    return *ps == NULL;
}

bool StackIsFull(const Stack *ps)
{
    Node *pnew;
    bool isFull = false;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew ==NULL)
    isFull = true;
    free(pnew);
    return isFull;
}

bool PushItem (Item item, Stack *ps)
{
    
    Node *pnew= (Node *)malloc(sizeof(Node));
    if(pnew==NULL)
    {
        fprintf(stderr,"Can not allocate memeory for new item!");
        return false;
    }
    pnew->item = item;
    if(*ps == NULL)
    pnew->previous = NULL;
    else
    {
        pnew->previous = *ps;
    }
    *ps = pnew;
    return true;
    
}

bool PopItem(Item *pi, Stack *ps)
{
    if(*ps==NULL)
    return false;
    else
    {
        *pi = (*ps)->item;
        Node * temp = *ps;
        *ps = (*ps)->previous;
        free(temp);
        return true;
    }
    

}

void EmptyTheStack(Stack *ps)
{
    Node* psave;
    while(*ps!=NULL)
    {
        psave = (*ps)->previous;
        free(*ps);
        *ps = psave;
    }
}

/*The following codes correspond to second Stack verison
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

void InitializeTheStack(Stack *pstack)
{
    pstack->top = NULL;
    pstack->count = 0;
}

bool StackIsEmpty(const Stack *pstack)
{
    return pstack->count ==0;
}

bool StackIsFull(const Stack *pstack)
{
    return pstack->count ==MAXITEMS;
}

bool PushItem(Item item, Stack *pstack)
{
    Node *pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        fprintf(stderr, "Can not allocate memory for new item!");
        return false;
    }
    pnew->item = item;
    if(pstack->top == NULL)
    {
        pstack->top = pnew;
    }
    else
    {
        pnew->previous = pstack->top;
    }
    pstack->count++;
    return true;
}

bool PopItem(Item *pitem, Stack *pstack)
{
    if(pstack->top == NULL)
    {
        fprintf(stderr, "Can not pop empty stack!");
        return false;
    }
    else
    {
        Node * temp;
        *pitem = (pstack->top)->item;
        temp = pstack->top->previous;
        free(pstack->top);
        pstack->top = temp;
        pstack->count--;
        return true;
    }
}

bool EmptyTheStack(Stack *pstack)
{
    Node *psave;
    psave = pstack->top->previous;
    while(pstack->top !=NULL)
    {
        psave = pstack->top->previous;
        free(pstack->top);
        pstack->top = psave;
    }
    return true;
}

*/