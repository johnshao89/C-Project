#include<stdio.h>
int set_mode(int mode);
void get_info(int mode, double *distance, double *gas);
void show_info(int mode, double *distance, double *gas);

int main(void)
{
    int the_mode;
    int choice;
    double *distance=NULL;
    double *gas=NULL;
    printf("Enter 0 for metric modem, 1 for US mode: ");
    scanf("%d", &the_mode);
    while(the_mode>=0)
    {
        choice = set_mode(the_mode);
        get_info(choice, distance, gas);
        show_info(choice, distance, gas);
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf("(-1 to quit):");
        scanf("%d", &the_mode);
    }
    printf("Done.\n");
    return 0;
}

int set_mode(int mode)
{
    if(mode==0)
    return 0;
    else if(mode ==1)
    return 1;
    else 
    printf("Invalid input!");
    
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

void show_info(int mode, double *distance, double *gas)
{
    if (mode==0)
    printf("Fuel consumption is %.2lf liters per 100 KM.\n", (*gas)/(*distance)*100);
    else if (mode==1)
    printf("Fuel consumption is %.1lf miles per gallon.\n", (*distance)/(*gas));
}