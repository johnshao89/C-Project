#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define FINISHED 1
#define MAXBKS 40
#define MAXTILT 40
#define MAXAULT 40
struct book{
    char title[MAXTILT];
    char author[MAXAULT];
    float value;
    bool delete;
};
int getlet(const char *st);
int getbook(struct book*);
void update(struct book *);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fp;
    struct book library[MAXBKS];
    int count=0, filecount, index,deleted=0;
    unsigned long int offset;
    struct book *pst = (struct book *)malloc(sizeof(struct book));
    if((fp = fopen("book.dat","r+b"))==NULL)
    {
        printf("Can not open file.\n");
        exit(EXIT_FAILURE);
    }
    while(count<MAXBKS && fread(&library[count],sizeof(struct book), 1, fp)==1)
    {
        if(count==0)
        printf("The content is:");
        printf("%s by %s, valued at $%.2f.\n", library[count].title, library[count].author, library[count].value);
        printf("Do you want to change or delete this entry?<y/n>");
        if(getlet("yn")=='y')
        {
            printf("Enter c to change, d for delte this entry:");
            if(getlet("cd")=='d')
            {
                library[count].delete = true;
                deleted++;
            }
            else 
            update(&library[count]);
        }
        count++;
    }
    fclose(fp);
    filecount = count-deleted;
    if(count==MAXBKS)
    {
        printf("The book.dat is full.\n");
        exit(EXIT_FAILURE);
    }
    int i=0;
    while(filecount<MAXBKS)
    {
        if(filecount<count)
        {
            while(library[i].delete == false)
            i++;
            if(getbook(&library[i])==FINISHED)
            break;
        }
        else if(getbook(&library[filecount])==FINISHED)
        break;
        filecount++;
        if(filecount<MAXBKS)
        puts("Enter the next book title.");
    }
    printf("Here is the list of your books:");
    
    if ((fp = fopen("book.dat","w"))==NULL)
    {
        printf("Can not open file.\n");
        exit(EXIT_FAILURE);
    }
    for(int index=0;index<filecount;index++)
    {
        if(library[index].delete==false)
        printf("%s by %s: &%.2f.\n", library[index].title, library[index].author, library[index].value);
        fwrite(&library[index], sizeof(struct book),1,fp);
    }
    fclose(fp);
    puts("Done!");
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

int getlet(const char *st)
{
    char ch;
    ch = getchar();
    if(strchr(st,ch)==NULL)
    {
        printf("Only enter a character in the list %s\n", st);
        while(getchar()!='\n')
        continue;
        ch = getchar();
    }
    while(getchar()!='\n')
    continue;
    return ch;
}

void update(struct book *ps)
{
    struct book copy;
    copy =*ps;
    puts("Enter the choice from following menu:");
    puts("t) Modify title   a) Modify author");
    puts("v) Modify value   s) Quit, save changes");
    puts("q) Quit, ignore changes");
    char ch;
    while((ch = getlet("tavsq"))!='s' && ch!='q')
    {
        switch (ch)
        {
        case 't':puts("Enter new title:");
            s_gets(copy.title, MAXTILT);
            break;
        case 'a': puts("Enter new author:");
            s_gets(copy.author,MAXAULT);
            break;
        case 'v': puts("Enter new value:");
            while(scanf("%f",&copy.value)!=1)
            {
                puts("Enter a numeric value:");
                scanf("f",&copy.value);
            }
            while(getchar()!='\n')
            continue;
            break;
        }
        puts("Enter the choice from following menu:");
        puts("t) Modify title   a) Modify author");
        puts("v) Modify value   s) Quit, save changes");
        puts("q) Quit, ignore changes");
    }
    if(ch =='s')
    *ps = copy;
}

int getbook(struct book *pst)
{
    int ret_val=0;
    printf("Enter the title:\n");
    if(s_gets(pst->title,MAXTILT)==NULL || pst->title[0]=='\0')
    ret_val = FINISHED;
    else
    {
        printf("Enter the author:\n");
        s_gets(pst->author,MAXAULT);
        printf("Enter the value:\n");
        scanf("%f",&pst->value);
    }
    pst->delete=false;
    while(getchar()!='\n')
    continue;
    return ret_val;   
}