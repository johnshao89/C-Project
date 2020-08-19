#include "stack.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(void)
{
    Stack *pstack = (Stack *)malloc(sizeof(Stack));
    InitializeTheStack(pstack);
    char input[40];
    puts("Enter a words:");
    scanf("%s", input);
    for(int i=0;input[i]!='\0';i++)
    PushItem(input[i],pstack);
    char c1[1];
    while(PopItem(c1,pstack))
    printf("%c",c1[0]);
    EmptyTheStack(pstack);
    return 0;
}
