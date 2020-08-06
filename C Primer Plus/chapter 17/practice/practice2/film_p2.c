#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

char *s_gets(char *st, int n);
void showitem(Item item);

int main(void)
{
    List *movie = (List*)malloc(sizeof(List));
    Item temp;
    InitializeList(movie);
    if(ListIsFull(movie))
    {
        fprintf(stderr, "The list if full!\n");
        exit(1);
    }
    puts("Enter the title of the film:");
    while(s_gets(temp.title,TSIZE)!=NULL && temp.title[0]!='\0')
    {
        puts("Enter the rating for the movie:");
        scanf("%d", &temp.rating);
        while(getchar()!='\n')
        continue;
        if(AddItem(temp,movie)==false)
        {
            fprintf(stderr,"Can not add to the list.\n");
            break;
        }
        if(ListIsFull(movie))
        {
            fprintf(stderr, "List is full.\n");
            break;
        }
        puts("Enter the next film:");
    }
    puts("The list content:");
    Traverse(movie,showitem);
    printf("You entered %d movies.\n", ListItemCount(movie));
    EmptyTheList(movie);
    puts("Done!");
    return 0;
}

void showitem(Item item)
{
    printf("%s with rating %d.\n", item.title,item.rating);
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