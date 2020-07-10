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
char *s_gets(char*st, int n);

int main(void)
{
    const struct month *pst = months;
    int tot=0,i;
    int day,year;
    char month_name[10];
    printf("Enter the day of the month:\n");
    while(scanf("%d", &day)==1)
    {
        printf("Enter the month of the year:\n");
        scanf("%s", month_name);
        printf("Enter the year:\n");
        scanf("%d", &year);
        for(i=0;i<12;i++)
        {
            if(strcmp(pst[i].name, month_name)!=0)
            tot+=pst[i].days;
            else break;
        }
        tot+=day;
        printf("There are %d days since the start of the year.\n",tot);
        printf("Enter next day.\n");
        tot =0;
    }
    printf("Done!");
    return 0;
}
