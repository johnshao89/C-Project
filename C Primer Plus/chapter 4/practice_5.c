#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[40], last_name[40];
    printf("Please enter your first name: ");
    scanf("%s", first_name);
    printf("Enter your last name: ");
    scanf("%s", last_name);
    printf("%s %s\n",first_name,last_name);
    printf("%*d %*d\n", strlen(first_name),strlen(first_name),strlen(last_name),strlen(last_name));
    printf("%d %*d\n",strlen(first_name),strlen(first_name),strlen(last_name));
    return 0;
}