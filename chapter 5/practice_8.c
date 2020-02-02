#include <stdio.h>

void Temperature (double temp_f);
int main(void)
{
    double temp_f;
    printf("Enter the temperature in F: ");
    while(scanf("%lf",&temp_f)) {
        Temperature(temp_f);
        printf("Enter the temperature in F: ");
    }
    return 0;
}

void Temperature(double temp_f)
{
    double temp_c = 5.0/9.0 *(temp_f-32.0);
    double temp_k = temp_c +273.16;
    printf ("%.2f C and %.2f K\n",temp_c,temp_k);
}