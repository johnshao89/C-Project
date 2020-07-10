#include<stdio.h>
#include<string.h>

struct month {
    char name[10];
    char abbrv[3];
    int days;
    int index;
};
const struct month months[12]={
    {"January", "JAN",31,1},
    {"February","FEB", 28,2},
    {"March","MAR",31,3},
    {"April","APR",30,4},
    {"May","MAY",31,5},
    {"June", "JUN",30,6},
    {"July","JUL",31,7},
    {"August","AUG",31,8},
    {"Septemmber","SEP",30,9},
    {"October","OCT",31,10},
    {"November","NOV",30,11},
    {"December","DEC",31,12}
};
 int main(void)
 {
     char choice[10];
     const struct month *pst = months;
     int i,tot=0;
     printf("Enter the month name:");
     scanf("%s", choice);
     for(i=0;i<12;i++)
     {
         tot+=months[i].days;
         if(strcmp(months[i].name, choice)==0)
         break;
     }
     printf("Until %s, the total days is %d.\n",choice,tot);
     return 0;

 }

