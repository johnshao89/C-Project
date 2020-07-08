#include<stdio.h>
#include<string.h>
#define MAX 81

char *reverse_string(char *string);
char *s_gets(char *st, int n);
int main(void)
{
    char string[MAX];
    char *output;
    while((output=reverse_string(string)))
    puts(output);
    puts("Done!");
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
char *reverse_string(char *string)
{
    s_gets(string, MAX);
    char temp;
    for (int i=0; i<strlen(string)/2;i++)
    {
        temp = string[i];
        string[i]= string[strlen(string)-1-i];
        string[strlen(string)-1-i]=temp;
    }
    return string;

}