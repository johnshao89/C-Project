#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);
void eatline(void);
void showmovies(struct film *head);

int main(void)
{
    struct film *head=NULL;
    struct film *prev, *current;
    char input[TSIZE];
    printf("Please enter the film title:\n");
    while(s_gets(input, TSIZE)!=NULL && input[0]!='\0')
    {
        current = (struct film* ) malloc(sizeof(struct film));
        if(head==NULL)
        head = current;
        else 
        prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);
        printf("Please enter the rating for this movie:\n");
        scanf("%d", &current->rating);
        eatline();
        prev = current;
        puts("Enter the next movie title:");
    }
    puts("Moive list:");
    showmovies(head);
    puts("Bye!");
    current = head;
    while(current!=NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }
    return 0;
}

void eatline(void)
{
    while(getchar()!='\n')
    continue;
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find = '\0';
        else eatline();
    }
    return ret_val;
}

void showmovies(struct film *head)
{
    if(head->next!=NULL)
    showmovies(head->next);
    printf("%s by the rating of %d.\n", head->title, head->rating);
}