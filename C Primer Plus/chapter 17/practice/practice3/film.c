#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

char *s_gets(char *st, int n);
void showitem(Item item);
void eatline(void);

int main(void)
{
    List *movie=(List *)malloc(sizeof(List)); //when delcare the List pointer, must give it a location.
    InitializeList(movie);
    Item temp;
    puts("Enter the first movie title:");
    while(s_gets(temp.title, TSIZE)!=NULL && temp.title[0]!='\0')
    {
        puts("Enter the rating for the movie:");
        scanf("%d", &temp.rating);
        eatline();
        if(ListIsFull(movie))
        {
            fprintf(stderr, "The list is full!");
            break;
        }
        if(AddItem(temp, movie)==false)
        {
            fprintf(stderr,"Can not add the item!");
            break;
        }
        puts("Enter the next movie title:");
    }
    if(ListIsEmpty(movie))
    {
        fprintf(stderr,"No data entered!");
        exit(1);
    }
    else
    {
        puts("Here is the list content:");
        Traverse(movie,showitem);
    }
    EmptyTheList(movie);
    puts("Bye!");
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
        else eatline();
    }
    return ret_val;
}

void showitem(Item item)
{
    printf("%s with rating %d.\n", item.title,item.rating);
}

void eatline(void)
{
    while(getchar()!='\n')
    continue;
}