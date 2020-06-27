#include<stdio.h>
#include<stdlib.h>
#define NUM 100

void descend(int array[]);
int main(void)
{
    int i;
    int input[NUM];
    for (i=0; i<NUM; i++)
    input[i]=(rand()%10+1);
    descend(input);
    for(i=0; i<NUM;i++)
    printf("%d\n",input[i]);
    return 0;

}

void descend(int array[])
{
    int top, seek, temp;
    for (top=0; top<NUM-1; top++)
    for(seek=top+1; seek<NUM;seek++)
    if(array[top]<array[seek])
    {
        temp = array[top];
        array[top]=array[seek];
        array[seek]=temp;
    }
    
}