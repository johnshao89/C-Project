#include<stdio.h>
int set_mode(int mode, int prev_mode);
void get_info(int mode, double *distance, double *gas);
void show_info(int mode, double distance, double gas);

int main(void)
{
    int the_mode, choice, prev_mode;
    double distance, gas;
    printf("Enter 0 for metric modem, 1 for US mode: ");
    scanf("%d", &the_mode);
    while(the_mode>=0)
    {
        prev_mode =set_mode(the_mode, prev_mode);
        get_info(prev_mode, &distance, &gas);
        show_info(prev_mode, distance, gas);
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf("(-1 to quit):");
        scanf("%d", &the_mode);
    }
    printf("Done.\n");
    return 0;
}

int set_mode(int mode, int prev_mode)
{
    if(mode !=0 && mode !=1)
    {
        printf("Invalide input!\n");
        return prev_mode;
    }
    else return mode;
    
}

void get_info(int mode, double *distance, double *gas)
{
    if(mode ==0)
    {
        printf("Enter distance traveled in kilometers:");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters:");
        scanf("%lf", gas);
    }
    else if(mode ==1)
    {
        printf("Enter distance traveled in miles:");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", gas);
    }
}

void show_info(int mode, double distance, double gas)
{
    if (mode==0)
    printf("Fuel consumption is %.2lf liters per 100 KM.\n", gas/distance*100);
    else if (mode==1)
    printf("Fuel consumption is %.1lf miles per gallon.\n", distance/gas);
}