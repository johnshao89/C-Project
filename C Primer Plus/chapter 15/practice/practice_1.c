#include<stdio.h>
#include<limits.h>
#include<string.h>

int btoi(char *);
char *s_gets(char *st, int n);

int main(void)
{
    char bstr[CHAR_BIT*sizeof(int)+1];
    int result;
    printf("Enter the bit string:\n");
    s_gets(bstr,CHAR_BIT*sizeof(int)+1);
    result=btoi(bstr);
    printf("The %s in decimal is %d.\n", bstr, result);
    return 0;
}

int btoi(char *st)
{
    int ret_val =0;
    int factor =1;
    while(*st!='\0')
        ret_val = 2*ret_val+(*st++ -'0');
    return ret_val;
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
        *find = '\0';
        else while (getchar()!='\n')
        continue;
    }
    return ret_val;
}