#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 81
char *s_gets(char *string, int num);
int count_letter(char *string);
int count_number(char *string);
int count_cap(char *string);
int count_low(char *string);
int count_punct(char *string);

int main(void)
{
    char string[MAX];
    puts("Enter a line to start (press Enter at the line beginning to quit):");
    while(s_gets(string, MAX)!=NULL && string[0]!='\0')
    {
        printf("The line has %d letters, %d superscript, %d subscripts, %d punctuation, %d numbers.\n",
        count_letter(string), count_cap(string),count_low(string), count_punct(string), count_number(string));
        puts("Enter next line.");
    }
    puts("Done!");
    return 0;
}

char *s_gets(char *string, int num)
{
    char *ret_val = fgets(string, num, stdin);
    int i=0;
    if(ret_val)
    {
        while(string[i]!='\n' && string[i]!='\0')
        i++;
        if(string[i]=='\n')
        string[i]='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

int count_letter(char *string)
{
    int ct=0;
    int state = 0;
    while(*string)
    {
        if(isspace(*string))
        state =0;
        else if (state ==0)
        {
            state =1;
            ct++;
        }
        string++;
    }
    return ct;
}

int count_number(char *string)
{
    int ct=0;
    while(*string)
    {
        if(isdigit(*string))
        ct++;
        string++;
    }
    return ct;
}

int count_cap(char *string)
{
    int ct=0;
    while(*string)
    {
        if(isupper(*string))
        ct++;
        string++;
    }
    return ct;
}

int count_low(char *string)
{
    int ct=0;
    while(*string)
    {
        if(islower(*string))
        ct++;
        string++;
    }
    return ct;
}

int count_punct(char *string)
{
    int ct=0;
    while(*string)
    {
        if(ispunct(*string))
        ct++;
        string++;
    }
    return ct;
}