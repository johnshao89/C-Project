#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
#define MAXPLP 5
struct person{
    unsigned long int SIN;
    struct{
        char first[LEN];
        char middle[LEN];
        char last[LEN];
    };
};
void print_struct(unsigned long int, char [], char [], char []);

char *s_gets(char *st, int n);

int main(void)
{
    int count=0;
    struct person people[MAXPLP];
    printf("Enter the first person's SIN:\n");
    while(count<MAXPLP && scanf("%lu", &people[count].SIN)==1)
    {
        while(getchar()!='\n')
        continue;
        printf("Enter the first name:\n");
        s_gets(people[count].first, LEN);
        printf("Enter the middle name:\n");
        s_gets(people[count].middle, LEN);
        printf("Enter the last name:\n");
        s_gets(people[count].last, LEN);
        count++;
        if(count<MAXPLP)
        printf("Enter the next person's SIN.\n");
    }
    for (int i=0;i<count;i++)
    print_struct(people[i].SIN, people[i].first,people[i].middle, people[i].last);
    printf("Done!");
    return 0;
}

void print_struct(unsigned long int sin, char first[], char middle[], char last[])
{
    if(strcmp(middle,"")!=0)
    printf("%s, %s %c. -- %ul.\n", last, first, middle[0], sin);
    else 
    printf("%s, %s --%lu.\n", last, first, sin);
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else 
        while(getchar()!='\n')
        continue;
    }
    return ret_val;
}