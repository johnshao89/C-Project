#include<stdio.h>
#include<limits.h>
int main(void)
{
    size_t num = _Alignof(int);
    printf("%d\n", num);
    printf("Char bit is %d",CHAR_BIT);
    printf("size of int is %d", sizeof(int));
    return 0;
}