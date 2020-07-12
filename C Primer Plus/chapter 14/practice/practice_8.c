#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LEN 40
struct seat{
    char id[LEN];
    bool booked;
    char first[LEN];
    char last[LEN];
};
char *s_gets(char *st, int n);
void showmenu(void);
char getlet(const char *);
void sort_seats(struct seat *p[]);
void assign_customer(struct seat[]);
void delete_assign(struct seat[]);


int main(void)
{
    char choice;
    struct seat seats[12]={
        {"A001",false},
        {"B001",false},
        {"C001",false},
        {"D001",true,"Wenjie","Shao"},
        {"A002",false},
        {"B002",false},
        {"C002",false},
        {"D002",false},
        {"A003",false},
        {"B003",false},
        {"C003",false},
        {"D003",false}
    };
    struct seat *p[12];
    int count,empty_seats=0;
    for(int i=0; i<12;i++)
    p[i]=&seats[i];
    while(true)
    {
        showmenu();
        choice = getlet("abcdef");
        switch (choice)
        {
        case 'a':
        for(count=0; count<12; count++)
        {
            if(seats[count].booked==false)
                empty_seats++;
        }
        printf("There are %d empty seats.\n", empty_seats);
            break;
        case 'b':
        printf("The empty seats id is:");
        for(count=0; count<12; count++)
        {
            if(seats[count].booked==false)
            printf("%s ", seats[count].id);
        }
            break;
        case 'c':sort_seats(p);
        break;
        case 'd':assign_customer(seats);
        break;
        case 'e':delete_assign(seats);
        break;
        case 'f':
        exit(EXIT_SUCCESS);
        }
        putchar('\n');
    }


}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
        *find = '\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}


char getlet(const char *st)
{
    char ret_val;
    ret_val=getchar();
    while(strchr(st,ret_val)==NULL)
    {
        printf("Only enter abcdef.\n");
        while(getchar()!='\n')
        continue;
        ret_val = getchar();
    }
    while(getchar()!='\n')
    continue;
    return ret_val;
}

void showmenu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
}
void sort_seats(struct seat *p[])
{
    int i, j;
    struct seat *temp;
    for(i=0;i<11;i++)
    for(j=i+1;j<12;j++)
    {
        if(strcmp(p[i]->id,p[j]->id)>0)
        {
            temp = p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
    for(i=0;i<12;i++)
    printf("%s ", p[i]->id);
    putchar('\n');
}

void assign_customer(struct seat seats[])
{
    char seat_id[LEN];
    char cust_first[LEN];
    char cust_last[LEN];
    int i;
    printf("Please enter the seats ID:");
    s_gets(seat_id,LEN);
    for(i=0;i<12;i++)
    {
        if(strncmp(seats[i].id,seat_id,4)==0)
        {
            printf("Enter the customer's first name:");
            s_gets(cust_first,LEN);
            strcpy(seats[i].first,cust_first);
            printf("Enter the customer's last name:");
            s_gets(cust_last,LEN);
            strcpy(seats[i].last,cust_last);
            seats[i].booked = true;
            break;
        }
    }
    printf("The seat you choose is %s",seat_id);
}

void delete_assign(struct seat seats[])
{
    char seat_id[LEN];
    int i;
    printf("Enter the seat ID you want to delete:");
    s_gets(seat_id,LEN);
    for(i=0;i<12;i++)
    {
        if(strncmp(seat_id,seats[i].id,4)==0)
        {
            strcpy(seats[i].first,"");
            strcpy(seats[i].last,"");
            seats[i].booked = false;
            break;
        }
    }
}