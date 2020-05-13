#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81

char *s_gets(char *st, int n);
char showmenu(void);
void ToUpper(char *);
void ToLower(char *);
void eatline(void);
void Dummy(char *);
void Transpose (char *);
void show(void (*fp)(char*), char *st);

int main(void)
{
    void (*pfun)(char *);
    char line[LEN];
    char choice;
    char copy[LEN];
    puts("Enter a line (empty to quit): ");
    while(s_gets(line, LEN)!=NULL && line[0]!='\0')
    {
        while ((choice = showmenu())!='n')
        {
            switch (choice)
            {
            case 'u': pfun = ToUpper; break;
            case 'l': pfun = ToLower; break;
            case 't': pfun = Transpose; break;
            case 'o': pfun = Dummy; break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a new string (empty to quit)");

    }
    puts("Bye");
    return 0;
}
void eatline(void)
{
    while (getchar()!='\n')
    continue;
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else 
        eatline();
    }
    return ret_val;
}



void ToUpper(char *str)
{
    while (*str)
    {
        if (islower(*str))
        {
            *str = toupper(*str);
            str++;
        }
    }
    
}

void ToLower(char *str)
{
    while(*str)
    {
        if(isupper(*str))
        {
            *str = toupper(*str);
            str++;
        }
    }
}

void Transpose (char *str)
{
    while(*str)
    {
        if(isupper(*str))
        *str = islower(*str);
        else if (islower(*str))
        *str = isupper(*str);
        str++;
    }
}

void Dummy(char *str)
{
    // no change
}

char showmenu(void)
{
    char ans;
    puts("Enter menu choice: ");
    puts("u) Upper case         l) Lower case");
    puts("t) Transposed case    o) Origine case");
    puts("n) Next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("ulton",ans)==NULL)
    {
        puts("Enter only a u,l,t,o,n");
        ans = tolower(getchar());
        eatline();
    }
    return ans;

}

void show(void (*fp)(char *str), char *st)
{   
    (*fp)(st);
    puts(st);
}