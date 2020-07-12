#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define LEN 40
#define FINISHED 0
struct seat{
    char id[LEN];
    bool booked;
    char first[LEN];
    char last[LEN];
};

struct flight{
    int flight_id;
    struct seat seats[LEN];
};

int flight_choice(struct flight[]); //accepts a array of flights and return flight id, 0 to terminate
void showmenu(void);
char get_letter(const char *st);
void show_empty(struct flight *);
void show_empty_list(struct flight *);
void show_sorted_seats(struct seat *[]);
void assign_customer(struct flight *);
void delete_customer(struct flight *);
void check_status(struct flight *);
char *s_gets(char*st, int n);
int main(void)
{
    struct flight flights[4]={
        {102},
        {311},
        {444},
        {519}
    };
    int id_index;
    char choice;
    id_index=flight_choice(flights);
    while(id_index!=FINISHED);
    {
        struct seat *p[LEN];
        for(int i=0;i<LEN;i++)
        p[i]= &(flights[id_index].seats[i]);
        showmenu();
        choice = get_letter("abcdefg");
        switch (choice)
        {
        case 'a':show_empty(&flights[id_index]);           
            break;
        case 'b': show_empty_list(&flights[id_index]);
            break;
        case 'c': show_sorted_seats(p);
            break;
        case 'd': assign_customer(&flights[id_index]);
            break;
        case 'e': delete_customer(&flights[id_index]);
            break;
        case 'f': check_status(&flights[id_index]);
            break;
        case 'g':
            break;
        }
        id_index = flight_choice(flights);
    }
    printf("Done!");
    return 0;
}

void showmenu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Double-check seat assignment");
    puts("g) Quit (back to previous menu");
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st,n,stdin);
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

char get_letter(const char *st)
{
    char ret_val;
    ret_val = getchar();
    while(strchr(st,ret_val)==NULL)
    {
        while(getchar()!='\n')
        continue;
        printf("Please only type %s.\n",st);
        ret_val = getchar();
    }
    while(getchar()!='\n')
    continue;
    return ret_val;
}

int flight_choice(struct flight flights[])
{
    int i, choice,index;
    printf("Please enter your flight choice from the below flight id:\n");
    printf("Enter q to quit.\n");
    for(i=0;i<4;i++)
    printf("%d; ", flights[i].flight_id);
    putchar('\n');
    scanf("%d", &choice);
    while(getchar()!='\n')
    continue;
    for(index=0;index<4;index++)
    {
        if(flights[index].flight_id == choice)
        break;
    }
    return index;
}

void show_empty(struct flight *pst)
{
    int i,count=0;
    for(i=0;i<LEN;i++)
    {
        if(pst->seats[i].booked==false)
        count++;
    }
    printf("There are %d empty seats for Flight %d.\n", count++,pst->flight_id);
}

void show_empty_list(struct flight *pst)
{
    int i;
    printf("The unbooked seats for Flight %d are: ", pst->flight_id);
    for(i=0;i<LEN;i++)
    {
        if(pst->seats[i].booked==false)
        printf("%s ", pst->seats[i].id);
    }
    putchar('\n');
}

void show_sorted_seats(struct seat *pst[])
{
    int i,j;
    struct seat *temp;
    for(i=0;i<LEN-1;i++)
    for(j=i+1;j<LEN;j++)
    {
        if(strcmp(pst[i]->id, pst[j]->id)>0)
        {
            temp = pst[i];
            pst[i]=pst[j];
            pst[j]=temp;
        }
    }
    printf("The unbooked seats are:");
    for(i=0;i<LEN;i++)
    printf("%s; ", pst[i]->id);
    putchar('\n');
}

void assign_customer(struct flight *pst)
{
    char choice[LEN], pick;
    int i;
    show_empty_list(pst);
    printf("Enter your choice: ");
    while(s_gets(choice, LEN)!=NULL && choice[0]!='\0')
    {
        for(i=0;i<LEN;i++)
        {
            if(strcmp(choice,pst->seats[i].id)==0)
            printf("Seat found!");
            pst->seats[i].booked = true;
            break;
        }
        printf("Enter the customer's first name:");
        s_gets(pst->seats[i].first,LEN);
        printf("Enter the customer's last name:");
        s_gets(pst->seats[i].last, LEN);
        printf("Want to book more seats?<y/n>");
        pick = get_letter("yn");
        if(pick=='y')
        {
            show_empty_list(pst);
            printf("Enter your choice:");
        }
        else 
        break;
    }
}

void delete_customer(struct flight *pst)
{
    char first[LEN], last[LEN], choice;
    int i;
    bool customer_found = false;
    printf("Enter the customer's first name to cancel the seat:");
    while(s_gets(first, LEN)!=NULL && first[0]!='\0')
    {
        for(i=0;i<LEN;i++)
        {
            if(strcmp(pst->seats[i].first,first)==0)
                {
                    printf("%s is found! Enter the customer's last name now:",first);
                    s_gets(last,LEN);
                    for(int k=i;k<LEN;k++)
                    {
                        if(strcmp(pst->seats[k].last,last)==0)
                        {
                            printf("Found the customer: %s %s.\n", first, last);
                            pst->seats[k].booked=false;
                            customer_found = true;
                            break;
                        }
                    }
                }
            break;
        }
        if(!customer_found)
        printf("Sorry, customer %s %s not found.!\n",first,last);
        printf("Do you want to delete another customer?<y/n>");
        choice = get_letter("yn");
        if(choice =='n')
        break;
        else
        printf("Enter the customer's first name to cancel seat:");
    }
    
}

void check_status(struct flight *pst)
{
    char seat_id[LEN], choice;
    bool seat_found=false;
    printf("Which seat do you want to check?\n");
    while(s_gets(seat_id,LEN)!=NULL && seat_id[0]!='\0')
    {
        for(int i=0;i<LEN;i++)
        if(strcmp(pst->seats[i].id,seat_id)==0)
        {
            seat_found=true;
            printf("Seat found!\n");
            printf("The status is %s.\n", pst->seats[i].booked);
            break;
        }
        if(!seat_found)
            printf("Seat not found!\n");
        printf("Do you want to start to check next seat?<y/n>");
        choice = get_letter("yn");
        if(choice =='n')
        break;
        else 
        printf("Which seat you want to check?\n");
    }
}