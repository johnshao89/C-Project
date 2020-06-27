#include<stdio.h>
void critic(int *unit);

int main(void)
{
    int pound;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &pound);
    while(pound!=56)
    critic(&pound);
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int *unit)
{
    printf("Guess again.\n");
    scanf("%d", unit);
}