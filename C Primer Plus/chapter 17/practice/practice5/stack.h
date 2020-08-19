#ifndef _STACK_H_
#define _STACK_H_
#include<stdbool.h>

typedef char Item;
typedef struct node {
    Item item;
    struct node* previous;
}Node;
typedef Node* Stack;

void InitializeTheStack(Stack * ps);

bool StackIsEmpty(const Stack *ps);

bool StackIsFull(const Stack *ps);

bool PushItem (Item item, Stack *ps);

bool PopItem(Item *pi, Stack *ps);

void EmptyTheStack(Stack *ps);

#endif

/* The second way to construct stack.h
#ifndef _STACK_H_
#define _STACK_H_
#define MAXITEMS 40
#include<stdbool.h>

typedef char Item;
typedef struct node {
    Item item;
    struct node *previous;
}Node;
typedef struct stack {
    Node * top;
    unsigned int count;
}Stack;

void InitializeTheStack(Stack *pstack);

bool StackIsEmpty(const Stack *pstack);

bool StackIsFull(const Stack *pstack);

bool PushItem(Item item, Stack *pstack);

bool PopItem(Item *pitem, Stack *pstack);

bool EmptyTheStack(Stack *pstack);

#endif

*/