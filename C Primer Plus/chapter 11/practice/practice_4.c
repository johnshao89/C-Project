#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 80
#define MAX 10

char *gets_n(char *str, int n);

int main(void)
{
    char input[LEN];
    char *output;
    int number;
    while(gets_n(input, MAX)!=NULL)
    puts(input);
    puts("Done!");
    return 0;    
}

char *gets_n(char *str, int n)
{
    int ch;
    char *orig = str;
    while((ch = getchar())!=EOF && isspace(ch))
    continue;
    if(ch ==EOF)
        return NULL;
    else
        *str++ = ch;
    while((ch = getchar())!=EOF && --n && !isspace(ch))
    {
        *str++ = ch;
    }
    *str = '\0';
    if (ch == EOF)
    return NULL;
    else 
    {
        while(ch !='\n')
        ch = getchar();
        return orig;
    }
}