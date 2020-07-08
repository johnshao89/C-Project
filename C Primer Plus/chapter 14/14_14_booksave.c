#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAULT 40
#define MAXBKS 10
struct book{
    char title[MAXTITL];
    char author[MAXAULT];
    float value;
};

char *s_gets(char *st, int n);

int main(void)
{
    int index,count=0, filecount;
    struct book library[MAXBKS];
    int size = sizeof(struct book);
    FILE *pbook;
    if((pbook = fopen("book.dat","a+w"))==NULL)
    {
        fputs("Can not open book.dat file.\n",stderr);
        exit(1);
    }
    rewind(pbook);
    while(count<MAXBKS && fread(&library[count],size,1,pbook)==1) //if pbbok has something to read into library[count]
    {
        if(count == 0)
        puts("Current content of the book.dat: ");
        printf("%s by %s, $%.2f\n", library[count].title,library[count].author,library[count].value);
        count++;
    }
    filecount = count; //locate how many books have been used
    if(count==MAXBKS)
    {
        puts("The book.dat is full.");
        exit(2);
    }
    puts("Enter a new title: ");
    puts("Press [enter] at the beginning to stop");
    while(count<MAXBKS && s_gets(library[count].title, MAXTITL)!=NULL && library[count].title[0]!='\0')
    {
        puts("Enter the author: ");
        s_gets(library[count].author, MAXAULT);
        puts("Enter the value: ");
        scanf("%f", &library[count++].value);
        while(getchar()!='\n')
        continue;
        if(count<MAXTITL)
        printf("Enter the next title");
    }
    if (count > 0)
    {
        puts("Here is your books: \n");
        for (index =0; index <count; index++)
        printf("%s by %s, $%.2f.\n", library[index].title, library[index].author, library[index].value);
        fwrite(&library[filecount], size, count-filecount,pbook); //add new books to pbook
    }
    else
    puts("No books, too bad.");
    puts("Bye.");
    fclose(pbook);
    return 0;
    
}

char *s_gets(char *st, int n)
{
    char *ret_val,*find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find = '\0';
        else
        {
            while(getchar()!='\n')
            continue;
        }

        
    }
            return ret_val;
}