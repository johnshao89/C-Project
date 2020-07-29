#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "queue.h"
#define MIN_PER_HOUR 60
bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    Queue line;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaway =0, customers=0, served=0, sum_line =0, wait_time =0;
    double min_per_cust;
    long line_wait =0;
    InitializeQueue(&line);
    srand((unsigned int)time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = hours*MIN_PER_HOUR;
    puts("Enter the average number of customers per hours:");
    scanf("%d", perhour);
    min_per_cust = MIN_PER_HOUR/perhour;

    for (cycle =0; cycle<cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(QueueIsFull(&line))
            turnaway++;
            else
            {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp,&line);
            }
        }

        if(wait_time<=0 && !QueueIsEmpty(&line))
        {
            DeQueue(&temp,&line);
            wait_time= temp.processtime;
            served++;
            line_wait = cycle - temp.processtime;
        }

        if(wait_time>0)
        wait_time--;
        sum_line+=QueueItemCount(&line);
    }
    
    if(customers>0)
            {
                printf("customers accepted: %ld\n", customers);
                printf("    turnaways: %ld\n", turnaway);
                printf("average queue size :%.2f\n", (double)sum_line/cyclelimit);
                printf("average wait time: %.2f\n",(double)line_wait/served);

            }
    else 
    puts("No customers!");
    EmptyTheQueue(&line);
    puts("Bye!");
    return 0;
}

bool newcustomer(double x)
{
    if (rand()*x/RAND_MAX <1)
    return true;
    else return false;
}
Item customertime(long when)
{
    Item ret_val;
    ret_val.arrive = when;
    ret_val.processtime = rand()%3 +1;
    return ret_val;
}