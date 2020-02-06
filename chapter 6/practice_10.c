#include <stdio.h>

int main(void)
{
    int low_num, high_num, total=0, i;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d %d",&low_num,&high_num)==2)
    {
        if (low_num<high_num)
            {for (i = low_num; i<=high_num;i++)
                total+=i*i;
            printf("The sums of the squares from %d to %d is %d\n", low_num*low_num,high_num*high_num,total);
            printf("Enter next set of limits: ");}
        else break;
    }
    printf("Done\n");
    return 0;
}