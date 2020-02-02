#include <stdio.h>
#define HOUR_TO_MIN 60
int main(void)
{
    int minutes, hours, left;
    printf("Enter the minutes: ");
    scanf("%d",&minutes);
    while (minutes>0) {
        hours = minutes/HOUR_TO_MIN;
        left = minutes%HOUR_TO_MIN;
        printf("%d minutes is %d hours and %d minutes\n",minutes,hours,left);
        printf("Enter another minutes, (<=0 to quit): ");
        scanf("%d", &minutes);
    }
    return 0;
}