#include <stdio.h>

int main(void)
{
    char first_name[40], last_name[40];
    printf("Please enter your first name: ");
    scanf("%s", first_name);
    printf("Please enter your last name: ");
    scanf("%s", last_name);
    printf("%s %s",first_name, last_name);
    return 0;
}