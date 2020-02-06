#include <stdio.h>

int main(void)
{
    int year=1,daphne_money=100,deirdre_money=100;

    while (daphne_money>=deirdre_money)
    {
        deirdre_money*=1.05;
        daphne_money+=100*0.1;
        year++;
    }
    printf("%d years later\n",year);
    return 0;

}