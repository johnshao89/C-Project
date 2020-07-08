#include<stdio.h>
#include<string.h>

#define MAX 81
int no_space(char *st);
char *s_gets(char *st, int n);

int main(void)
{
    char input[MAX];
    puts("Enter a string with space:");
    while(no_space(input))
    {
        puts(input);
        puts("Enter another string with space.");
    }
    puts("Done!");
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i =0;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        while(st[i]!='\n' && st[i]!='\0')
        i++;
        if(st[i]=='\n')
        st[i]='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

int no_space(char *st)
{
    s_gets(st, MAX);
    int space_ct=0;
    while(1)
    {
        if(*st == ' ')
        space_ct++;
        else
        {
            *(st-space_ct) = *st;
        }
        if (*st=='\0')
        break;
        st++;
        
    }
    return 1;
}