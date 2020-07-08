#include<string.h>
#include<stdio.h>
#define LEN 10

char *stringsrc(char *str, char ch);
char *s_gets(char *st, int n);

int main(void)
{
    char input[LEN];
    char ch;
    char *output;
    printf("Please enter a string:\n");
    while(s_gets(input, LEN))
    {
        puts("Please enter a character to search:");
        scanf("%c", &ch);                           //scanf()would store '\n' as in the buffer. If do not deal with it, the '\n' would be used as input for s_gets()
        while(getchar()!='\n') 
        continue;
        output = stringsrc(input, ch);
        puts(output);
        printf("Please enter another string.\n");
    }
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
char *stringsrc(char *str, char ch)
{
    for (int i =0; i< strlen(str); i++)
    {
        if(str[i] == ch)
        return &str[i];
    }
    return NULL;
    
}