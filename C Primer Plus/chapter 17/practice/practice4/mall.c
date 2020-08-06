//Rewrite the mall.c in the testbook, using two queues to simulate
#include<stdio.h>
#include"queue.h"
#include<stdlib.h>
#include <math.h>
#include<time.h>
#define MIN_PER_HOUR 60

bool newcustomer(double x);
Item setCustomer(long when );
void eatline(void);

int main(void)
{
    Queue team[2];
    Item temp; //used to store customer's info
    int hours,cust_per_hour,cycle,wait_time=0;
    int customers=0,turnaway=0,served=0;
    long cyclelimits,sum_wait=0; //sum_wait for total wait time
    double min_per_cust;
    int sum_line=0;
    srand((unsigned int)time(0));
    puts("Enter the hours you want to simulate:");
    scanf("%d", &hours);
    eatline();
    puts("Enter the number of customers per hour:");
    scanf("%d", &cust_per_hour);
    eatline();
    min_per_cust = MIN_PER_HOUR/cust_per_hour;
    cyclelimits = hours*MIN_PER_HOUR;
    for(int i=0;i<2;i++)
    {
        InitializeQueue(&team[i]);
        for(cycle=0; cycle<cyclelimits;cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(QueueIsFull(&team[i]))
                turnaway++;
                else
                {
                    temp = setCustomer(cycle);
                    EnQueue(temp,&team[i]);
                    customers++;
                }
            }    
            if(!QueueIsEmpty(&team[i]) && wait_time<=0)
                {
                    served++;
                    DeQueue(&temp,&team[i]); // let the first customer of the queue to get served
                    wait_time = temp.processtime;
                    sum_wait += cycle - temp.arrive;
                }
            if(wait_time>0)
                wait_time--;
                sum_line+=QueueItemCount(&team[i]);
        }
        if(customers>0)
        {
            printf("For queue# %d:\n", i+1);
            printf("Customers accepted: %ld", customers);
            printf("    %ld turnaways.",turnaway);
            printf("    Average wait time: %.2lf minutes\n", (double)sum_wait/cyclelimits);
        }
        EmptyTheQueue(&team[i]);
    }
    puts("Bye!");
}

void eatline(void)
{
    while(getchar()!='\n')
    continue;
}

bool newcustomer(double x)
{
    if((x * rand() /RAND_MAX)<1)
    return true;
    else return false;
}
Item setCustomer(long when )
{
    Item ret_val;
    ret_val.arrive = when;
    ret_val.processtime = rand()%3+1;
    return ret_val;
}