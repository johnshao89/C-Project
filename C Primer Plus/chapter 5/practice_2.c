#include <stdio.h>

int main(void)
{
    int number,count=0;
    printf("Please enter a number: ");
    scanf("%d",&number);
    while (count++<=10) {
        printf("%d ", number);
        number++;
    }
    return 0;
}