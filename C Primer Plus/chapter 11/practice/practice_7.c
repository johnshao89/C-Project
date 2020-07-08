#include<stdio.h>
#include<string.h>
#define MAX 81

char *mystrncpy(char *target, char *source, int n);
char *s_gets(char *st, int n);
int main(void)
{
    char source[MAX];
    char target[MAX];
    char *output;
    puts("Enter a source string:");
    s_gets(source,MAX);
    puts("Enter a target string:");
    s_gets(target, MAX);
    output = mystrncpy(target, source, MAX);
    puts(output);
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i=0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while(st[i]!='\0' && st[i]!='\n')
        i++;
        if(st[i] == '\n')
        st[i]='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}
char *mystrncpy(char *target, char *source, int n)
{
    if(strlen(source)<n)
    {
        for (int i=0; i<strlen(source); i++)
        target[i] = source[i];
    }
    else
    {
        for (int i=0; i<n; i++)
        target[i] = source[i];
        target[n]='\0';
    }
    return target;
    
    
}