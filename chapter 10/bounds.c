#include <stdio.h>
#define SIZE 4

int main(void)
{
    int value1 = 14;
    int arr[SIZE];
    int value2 = 88;
    int i;
    printf("Value1 = %d, value = %d\n",value1, value2);
    for (i = -1; i<=SIZE;i++)
    arr[i]=2*i+1;
    for (i = -1; i<7; i++)
    printf("%2d %d\n",i, arr[i]);
    printf("Value 1 = %d, value 2 =%d\n", value1,value2);
    printf("address of arr[-1]: %p\n",&arr[-1]);
    printf("address of arr[4]: %p\n",&arr[4]);
    printf("address of value1: %p\n",&value1);
    printf("address of value2: %p\n",&value2);
    return 0;
}
