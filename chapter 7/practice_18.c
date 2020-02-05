#include <stdio.h>

int main(void)
{
    int first =5, week=0, left;
    while (left<=150)
    {
        week++;
        left = (first-week)*2;
        first = left;
    }
    printf("In %d weeks got over 150 friends\n",week);
    return 0;
}