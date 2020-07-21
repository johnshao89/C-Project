#include<stdio.h>
#include<limits.h>
#include<assert.h>
unsigned int rotate_l(unsigned int, int);
char *itob(int, char *);
int main(void)
{
    int input, num, result;
    printf("Enter an integer and rotate number:");
    scanf("%d %d", &input, &num);
    char b_string[CHAR_BIT*sizeof(int)+1];
    printf("Before the rotate: ");
    printf("%d is %s in bit.\n", input, itob(input, b_string));
    //assert(1>2);
    result = rotate_l(input, num);
    printf("After rotate, %d is %s\n", result, itob(result, b_string));    
    return 0;
}

char *itob(int value, char *b_str)
{
    int size = CHAR_BIT*sizeof(int);
    int index;
    for(index = size-1; index>=0; index--, value>>=1)
    b_str[index]=(value&01)+'0';
    b_str[size]='\0';
    return b_str;
}

unsigned int rotate_l(unsigned int value, int num)
{
    char b_str[CHAR_BIT*sizeof(int)+1];
    itob(value, b_str);
    for(int i=0; i<num; i++)
    {
        value<<=1;
        value+=b_str[i]-'0';
    }
    return value;
}



