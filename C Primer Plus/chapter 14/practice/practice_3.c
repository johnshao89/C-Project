#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTILT 40
#define MAXAULT 40
#define MAXBKS 40

struct book{
    char title[MAXTILT];
    char author[MAXAULT];
    float value;
};
char*s_gets(char*st, int n);
void showcontent(struct book *);
void sort_first_letter(struct book *[], int n);
void sort_value(struct book *[], int n);

int main(void)
{
    struct book library[MAXBKS];
    struct book *pst[MAXBKS];
    int count=0;
    printf("Enter the book title:\n");
    while(count<MAXBKS && s_gets(library[count].title, MAXTILT)!=NULL && library[count].title[0]!='\0')
    {
        printf("Now enter the name of the author:\n");
        s_gets(library[count].author, MAXAULT);
        printf("Now enter the value of the book:\n");
        scanf("%f",&library[count].value);
        while(getchar()!='\n')
        continue;
        pst[count] = &library[count];
        count++;
        if(count<MAXBKS)
        printf("Enter the next book title:\n");
    }
    sort_first_letter(pst,count);
    sort_value(pst, count);
    return 0;


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
        else while (getchar()!='\n')
        continue;
    }
    return ret_val;
}
void showcontent(struct book *library)
{
    printf("%s by %s, valued %.2f.\n", library->title, library->author, library->value);
}

void sort_first_letter(struct book *library[], int n)
{
    struct book *temp;
    int i, j;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if (strcmp(library[i]->title, library[j]->title)>0)
        {
            temp = library[i];
            library[i]=library[j];
            library[i]=temp;
        }
    }
    for(i=0;i<n;i++)
    showcontent(library[i]);
}
void sort_value(struct book *library[], int n)
{
    struct book *temp;
    int i,j;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(library[i]->value>library[j]->value)
        {
            temp = library[i];
            library[i]=library[j];
            library[j]=temp;
        }
    }
    for(i=0;i<n;i++)
    showcontent(library[i]);

}