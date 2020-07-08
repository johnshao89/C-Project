#include<stdio.h>
#include<string.h>
#define MAX 10

char *gets_n(char *st, int n);

int main(void)
{
    char input[MAX];
    char *output;
    puts("Enter characters.");
    output = gets_n(input, MAX-1);
    if(output ==NULL)
    puts("Failed input.");
    else
    {
        puts(output);
    }
    
    return 0;
}

char *gets_n(char *st, int n)
{
    int i;
    char ch;
    for (i=0; i< n; i++)
    {
        ch = getchar();
        if(ch!=EOF)
        st[i]=ch;
        else 
        break;
    }
    if(ch == EOF)
    return NULL;
    else
    {
        st[i]='\0';
        return st;
    }
    
    
}