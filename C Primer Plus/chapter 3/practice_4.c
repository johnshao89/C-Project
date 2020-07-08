#include <stdio.h>
int main(void)
{
    double sec_in_year =3.156e7;
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("\n%e",age*sec_in_year);
    return 0; 
}