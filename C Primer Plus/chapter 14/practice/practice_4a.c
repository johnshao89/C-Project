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
char *s_gets(char *st, int n);
void print_struct(struct person [], int n);
int main(void)
{
    int count=0;
    struct person people[MAXPLP];
    printf("Enter the person's SIN number:\nPress # at the new line to stop.\n");
    while(count < MAXPLP && scanf("%lu", &people[count].SIN)==1)
    {
        while(getchar()!='\n')
        continue;
        printf("Enter the person's first name:\n");
        s_gets(people[count].first, LEN);
        printf("Enter the person's middle name:\n");
        s_gets(people[count].middle, LEN);
        printf("Enter person's last name:\n");
        s_gets(people[count].last, LEN);
        count++;
        if(count<MAXPLP)
        printf("Enter next person's SIN:\n");
    }
    print_struct(people, count);
    printf("Done!\n");
    return 0;
    
}
char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find ='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

void print_struct(struct person people[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(people[i].middle[0]!='\0')
        printf("%s, %s %c.--%lu\n", people[i].last,people[i].first,people[i].middle[0],people[i].SIN);
        else 
        printf("%s, %s--%lu\n", people[i].last,people[i].first,people[i].SIN);
    }
}
