#include<stdio.h>
#include<string.h>
#define LEN 10

char *gets_n(char *str, int n);

int main(void)
{
    char input[LEN];
    char *output;
    puts("Enter several characters:");
    output = gets_n(input, LEN-1);
    if (output ==NULL)
    puts("Failed input.");
    else 
    puts(output);
    puts("Done!");
    return 0;
}

char *gets_n(char *str, int n)
{
    int i;
    char ch;
    for (i=0; i< n; i++)
    {
        ch = getchar();
        if (!isspace(ch) && ch!=EOF) //isspace() used to check space, new line, etc
        str[i]=ch;
        else break;
    }
    if (ch==EOF)
    return NULL;
    else
    {
        str[i]='\0';
        return str;
    }
    
}