#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXBKS 40
#define MAXTILE 40
#define MAXAULT 40
#define FINISHED 1
struct book{
    char title[MAXTILE];
    char author[MAXAULT];
    float value;
    bool deleted;
};

char *s_gets(char *st, int n); //function to accept a line of string
char get_letter(char *); //function to accept a first letter and return it
void showmenu(void); //show manipulation
void update(struct book *);
int add_book(struct book *);

int main(void)
{
    FILE *fp;
    struct book library[MAXBKS];
    int count=0,filecount, delete=0;
    char choice;
    int i=0;
    if((fp = fopen("book.dat","r+b"))==NULL)
    {
        printf("Can not find book.dat file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    while(count<MAXBKS && fread(&library[count],sizeof(struct book),1,fp)==1)
    {
        if(count==0)
        printf("The content of the file is:\n");
        printf("%s by %s: &%.2f.\n", library[count].title, library[count].author, library[count].value);
        printf("Do you want to change or delete this entry?<y/n>");
        if((choice = get_letter("yn"))=='y')
        {
            printf("Do you want to make changes or delete?<cd>");
            choice = get_letter("cd");
            if(choice == 'c')
            {
                showmenu(); 
                update(&library[count]);
            }
            else
            {
                delete++;
                library[count].deleted = true;
            }            
        }
        count++;    
    }
    filecount = count-delete; //how many books not deleted
    fclose(fp);
    if(count==MAXBKS)
    {
        printf("The book.dat is full.\n");
        exit(EXIT_FAILURE);
    }
    printf("Please add a book to the library.\n");
    printf("Enter the book's title: ");
    while(filecount<MAXBKS)
        {
            if(filecount<count)
            {
                while(library[i].deleted==false)
                i++;
                if(add_book(&library[i])==FINISHED)
                break;
            }
            else
            {
                if(add_book(&library[filecount])==FINISHED)
                break;
            }
            filecount++;
        }
    fp = fopen("book.dat","w");
    for(int index=0; index<filecount;index++)
    {
        if(library[index].deleted==false)
        fwrite(library, sizeof(struct book),1,fp);
    }
    fclose(fp);
    puts("Done!");
    return 0;
}

void showmenu(void)
{
    puts("Choose the alphabetical number:");
    puts("a) Modify the title   b) Modify the author");
    puts("c) Modify the value   d) Quit and save changes");
    puts("e) Quit and abort changes");
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
        *find ='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

char get_letter(char *st)
{
    char ret_val;
    ret_val = getchar();
    if(strchr(st,ret_val)==NULL)
    {
        printf("Please only enter %s.",st);
        while(getchar()!='\n')
        continue;
        ret_val = getchar();
    }
    while(getchar()!='\n')
    continue;
    return ret_val;

}

int add_book(struct book *pst)
{
    int ret_val=0;
    printf("Please enter the title: Press ENTER at new line to stop.\n");
    if(s_gets(pst->title,MAXTILE)==NULL || pst->title[0]=='\0')
    ret_val =FINISHED;
    else
    {
        printf("Enter the author's name:\n");
        s_gets(pst->author, MAXAULT);
        printf("Enter the value:\n");
        scanf("%f", &pst->value);
        while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

void update(struct book *pst)
{
    struct book copy;
    char choice;
    copy = *pst;
    choice = get_letter("abcde");
    while(choice!='d'&&choice!='e')
    {
        switch (choice)
        {
        case 'a':
            printf("Enter the new title:");
            s_gets(copy.title,MAXTILE);
            break;
        case 'b':
            printf("Enter the new author:\n");
            s_gets(copy.author, MAXAULT);
            break;
        case 'c':
            printf("Enter the new value:\n");
            scanf("%f", &copy.value);
            while(getchar()!='\n')
            continue;
            break;
        }
        showmenu();
        choice=get_letter("abcde");
    }
    if(choice == 'd')
    *pst = copy;

}
