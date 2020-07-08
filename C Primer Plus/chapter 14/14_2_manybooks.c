#include <stdio.h>
#include <string.h>
#define MAXBOOKS 100
#define MAXTITLE 40
#define MAXAULT 40
char *s_gets(char *st, int n);
struct book {
    char title[MAXTITLE];
    char author[MAXAULT];
    float value;
};

int main(void)
{
    int count=0, index;
    struct book library[MAXBOOKS];
    printf("Enter the title of the book\nPress [enter] to stop\n");
    while(count < MAXBOOKS && s_gets(library[count].title, MAXTITLE)!=NULL && library[count].title[0]!='\0')
    {
        printf("Enter the name of author\n");
        s_gets(library[count].author, MAXAULT);
        printf("Now enter the value\n");
        scanf("%f",&library[count++].value);
        while(getchar()!='\n')
        continue;
        if (count < MAXBOOKS)
        printf("Enter the next book title\n");
    }
    if(count>0)
    {
        printf("Here is the list of books:\n");
        for (index=0; index <count; index++)
        printf("%s by %s : $%.2f\n",library[index].title, library[index].author, library[index].value);
    }
    else
    printf("No books, too bad\n");
    return 0;
    
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else
        while(getchar()!='\n')
        continue;
    }
    return ret_val;
}