#include<stdio.h>
void swap(int *[]);
int main(void)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *pst[10];
    for (int i=0;i<10;i++)
    pst[i]=&array[i];
    swap(pst);
    return 0;
}

void swap(int *p[10])
{
    int i,k;
    int temp;
    for(i=0;i<9;i++)
    for(k=i+1;k<10;k++)
    if(*p[i]<*p[k])
    {
        temp = *p[i];
        *p[i] =*p[k];
        *p[k] = temp;
    }
    for(i=0;i<10;i++)
    printf("%d ", *p[i]);
}