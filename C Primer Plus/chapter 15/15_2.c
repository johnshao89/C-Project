#include<stdio.h>
#include<limits.h>

char *itobs(int, char *);
int invert_end(int *, int);
void show_bstr(const char *);

int main(void)
{
    int number;
    int digits;
    char b_str[CHAR_BIT*sizeof(int)+1];
    printf("Enter a number to start:\n");
    scanf("%d", &number);
    itobs(number,b_str);
    show_bstr(b_str);
    printf("How many number of bits you want to invert?\n");
    scanf("%d", &digits);
    invert_end(&number,digits);
    itobs(number,b_str);
    printf("After invert:\n");
    show_bstr(b_str);
    return 0;
}

char *itobs(int n, char *st)
{
    int size = CHAR_BIT*sizeof(int);
    int i;
    for(i=size-1;i>=0;i--)
    {
        st[i] = (n&01)+'0';
        n>>=1;
    }
    st[size]='\0';
    return st;
}

int invert_end(int *n, int bits)
{
    int mask =0;
    int bitval =1;
    while(bits--)
    {
        mask|=bitval;
        bitval<<=1;
    }
    *n = (*n)^mask;
    return 1;
    
}

void show_bstr(const char *st)
{
    while(*st)
    {
        putchar(*st);
        st++;
    }
}