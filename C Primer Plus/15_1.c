#include<stdio.h>
#include<limits.h>

char *itobs(int, char *);

void show_bstr(const char *);

int main(void)
{
    char b_str[CHAR_BIT*sizeof(int)+1];
    int number;
    printf("Enter the number to start:\n");
    scanf("%d", &number);
    itobs(number, b_str);
    show_bstr(b_str);
    return 0;
}

char *itobs(int num, char *str)
{
    int size = CHAR_BIT*sizeof(int);
    int i;
    for(i=size-1;i>=0;i--)
    {
        str[i]=(num & 01)+'0';
        num>>=1;
    }
    str[size]='\0';
    return str;
}

void show_bstr(const char *str)
{
    while(*str)
    {
        putchar(*str);
        str++;
    }
}