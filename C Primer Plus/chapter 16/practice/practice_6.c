#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 40
typedef struct names{
    char first[LEN];
    char last[LEN];
}Names;

void fillnames(Names *);
void shownames(Names *);
void eatline(void);
int mycomp(const void*p1, const void*p2);
char *s_gets(char *st, int n);

int main(void)
{
    int num;
    printf("How many persons you want to compare?\n");
    scanf("%d", &num);
    eatline();
    Names *person = (Names *)malloc(sizeof(Names)*num);
    for(int i=0;i<num;i++)
    fillnames(&person[i]);
    printf("Here is what you entered before sorting:\n");
    for(int i=0;i<num;i++)
    shownames(&person[i]);
    qsort(person,num,sizeof(Names),mycomp);
    printf("Here are the names after sorting:\n");
    for(int i=0;i<num;i++)
    shownames(&person[i]);
    free(person);
    return 0;
    
}

void fillnames(Names * pst)
{
    printf("Enter the first name: ");
    s_gets(pst->first,LEN);
    printf("Enter the last name: ");
    s_gets(pst->last,LEN);
}

void shownames(Names *pst)
{
    printf("%s %s\n",pst->first,pst->last);
}

void eatline(void)
{
    while(getchar()!='\n')
    continue;
}

int mycomp(const void*p1, const void*p2)
{
    const Names *a1 = (const Names *) p1;
    const Names *a2 = (const Names *) p2;
    if(strcmp(a1->first, a2->first)>0)
    return 1;
    else if (strcmp(a1->first, a2->first)<0)
    return -1;
    else return strcmp(a1->last, a2->last);
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
