#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 81
int my_atoi(char *string);
char *s_gets(char *st, int n);
int main(void)
{
    char input[MAX];
    int output;
    s_gets(input, MAX);
    output = my_atoi(input);
    printf("The result is %d.\n", output);
    return 0;
    
}

char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, MAX, stdin);
    int i=0;
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

int my_atoi(char *string)
{
    int sum =0;

    while(*string!='\0')
    {
        if(!isdigit(*string))
            return 0;
        else 
        {
            sum*=10;
            sum+= *string-'0';
        }
        string++;
    }
    return sum;
}