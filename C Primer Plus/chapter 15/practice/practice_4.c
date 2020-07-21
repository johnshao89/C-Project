#include<stdio.h>

int pos_value(int, int);

int main(void)
{
    int input, position;
    printf("Enter the value and the position: ");
    while(scanf("%d %d", &input, &position)==2)
    {
        printf("The %d bits in value %d is %d.\n", position, input, pos_value(input, position));
        printf("\nEnter the next pair of values and position:");
    }
    return 0;
}

int pos_value(int value, int pos)
{
    int ret_val;
    value>>=(pos-1);
    ret_val = value&01;
    return ret_val;
}