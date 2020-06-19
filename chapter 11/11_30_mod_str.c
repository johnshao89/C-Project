#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LIMIT 81

void ToUpper(char *);
int PunctCount(char *);

int main(void)
{
    char line[LIMIT];
    char *find;
    puts("Enter a line:");
    fgets(line,LIMIT,stdin);
    find = strchr(line,'\n');
    if (find)
    *find ='\0';
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuations.\n",PunctCount(line));
    return 0;
}

void ToUpper(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(char *str)
{
    int ct =0;
    while(*str)
    {
        if (ispunct(*str))
        ct++;
        str++;
    }
    return ct;
}