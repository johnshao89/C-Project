#include <stdio.h>
#include <string.h>
int main(void)
{
    char first_name[40], last_name[40];
    printf("Please enter your first name: ");
    scanf("%s", first_name);
    printf("Please enter your last name: ");
    scanf("%s", last_name);
    int n_first_name = strlen(first_name);
    printf("%20s %s\n",first_name, last_name);
    printf("%s %-20s\n",first_name, last_name);
    return 0;
}