#include<stdio.h>
#include "practice_2_b.h"
#define MAX 81

static double distance, gas;
static int the_mode;
void set_mode(int mode)
{
    if(mode==0)
    the_mode=0;
    else if (mode ==1)
    the_mode=1;
    else
    {
        printf("Invalid mode specified. Mode %d(US) used.\n", the_mode);
    }
    
}

void get_info(void)
{
    if(the_mode ==0)
    {
        printf("Enter distance traveled in kilometers:");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters:");
        scanf("%lf", &gas);
    }
    else if(the_mode ==1)
    {
        printf("Enter distance traveled in miles:");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", &gas);
    }
}

void show_info(void)
{
    if (the_mode==0)
    printf("Fuel consumption is %.2lf liters per 100 KM.\n", gas/distance*100);
    else if (the_mode==1)
    printf("Fuel consumption is %.1lf miles per gallon.\n", distance/gas);
}
