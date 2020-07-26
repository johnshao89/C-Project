#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 40

struct film{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);

int main(void)
{
    struct film *head=NULL;
    struct film *prev, *current;
    char input[TSIZE];
    puts("Enter the book title:");
    while(s_gets(input, TSIZE)!=NULL && input[0]!='\0')
    {
        current = (struct film*)malloc(sizeof(struct film));
        if(head==NULL)
        head = current;
        else
        prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);
        puts("Enter the rating now:");
        scanf("%d", &current->rating);
        while(getchar()!='\n')
        continue;
        prev = current;
        puts("Enter the next title:");
    }

    if(head==NULL)
    printf("No data!");
    else
    {
        current = head;
        while(current!=NULL);
        {
            printf("%s, %d\n", current->title,current->rating);
            current = current->next;
        }
    }

    // free memory
    current = head;
    while(current!=NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    puts("Done!");
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
        *find = '\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}