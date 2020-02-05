#include <stdio.h>

int main(void)
{
    int array[8],i,sum=1;
    for (i=0;i<8;i++)
    {
        sum*=2;
        array[i]=sum;
    }
    i=0;
    do
    {
        printf("%d\n",array[i]);
    } while (i++<7);
    return 0;
    
}