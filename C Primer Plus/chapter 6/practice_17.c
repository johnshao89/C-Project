#include <stdio.h>

int main(void)
{
    double first =100, left=100,total;
    int year =0;
    while (left>0)
    {
        total=first*1.08;
        left = total -10;
        first = left;
        year++;
    }
    printf("In %d years withdraw all money\n",year);
    return 0;
}