#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int btoi(const char *);
char *itob(int, char *);

int main(int argc, char *argv[])
{
    int bit1, bit2;
    int size = CHAR_BIT*sizeof(int)+1;
    char bstr[size];
    if(argc!=3)
    {
        printf("Usage: filename bit_str bit_str\n");
        exit(EXIT_FAILURE);
    }
    bit1 = btoi(argv[1]);
    bit2 = btoi(argv[2]);
    
    printf("After bit AND &, the result is %s.\n", itob(bit1&bit2,bstr));
    printf("After bit OR |, the result is %s.\n", itob(bit1|bit2, bstr));
    printf("After bit XOR ^, the result is %s.\n", itob(bit1^bit2, bstr));
    return 0;
}

int btoi(const char *st)
{
    int ret_val=0;
    while(*st!='\0')
    ret_val = 2*ret_val +(*st++ -'0');
    return ret_val;
}

char *itob(int n, char *st)
{
    int size = CHAR_BIT*sizeof(int);
    for (int i=size-1;i>=0;i--)
    {
        st[i]= (n&01) +'0';
        n>>=1;
    }
    st[size]='\0';
    return st;
}