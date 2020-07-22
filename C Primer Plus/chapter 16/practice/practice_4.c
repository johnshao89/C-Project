#include<stdio.h>
#include<time.h>
void delay(double clock_time);

int main()
{
    double delay_time;
    printf("Enter the elapsed time in seconds:\n");
    scanf("%lf", &delay_time);
    clock_t start, end;
    start = clock();
    delay(delay_time);
    end = clock();
    double time_elapsed =(end-start)/CLOCKS_PER_SEC;
    printf("The function costs %lf seconds.\n", time_elapsed);
    return 0;
}

void delay(double clock_time)
{
    clock_t start, end;
    start = clock();
    do
    {
        end = clock();
    } while ((double)(end-start)/CLOCKS_PER_SEC<clock_time);
}