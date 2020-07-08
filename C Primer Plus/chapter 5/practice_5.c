#include <stdio.h>

int main(void)
{
    int days, current_money=1, total_money=0;
    printf("Enter the days to make money: ");
    scanf("%d",&days);
    while (days-->0) {
        current_money = (days+1)*(days+1);
        total_money+=current_money;
    }
    printf("Total money you make is %d\n",total_money);
    return 0;
}