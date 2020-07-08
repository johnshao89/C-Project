#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 81
#define LIM 10

void show_menu(void);
void display_orig(char string[][MAX], int num);
void display_array(char *string[], int num);
void display_array_ascii(char *string[], int num);
void display_array_length(char *string[], int num);
void display_array_first(char *string[], int num);
int first_letter_len(char *string);
char *s_gets(char *st, int n);

int main(void)
{
    char input[LIM][MAX];
    char *copy[LIM];
    int ct=0;
    char choice;
    puts("Enter a string: (press Enter at the beginning of new line to quit)");
    while(ct<LIM && s_gets(input[ct], MAX)!=NULL && input[ct][0]!='\0')
        {
            copy[ct] = input[ct];
            ct++;
            puts("Enter another string");
        }
    show_menu();
    while(scanf("%c", &choice)==1)
    {
        while(getchar()!='\n')
        continue;
        if(choice =='q')
        break;
        else
        {
            switch (choice)
            {
            case 'a':
                display_orig(input, ct);
                break;
            case 'b':
                display_array_ascii(copy, ct);
                break;
            case 'c':
                display_array_length(copy, ct);
                break;
            case 'd':
                display_array_first(copy, ct);
                break;
            default:
                puts("Input not accepted, please only enter a,b,c,d or q.");
            }
        }
        show_menu();
    }
    puts("Program ended!");
    return 0;

}

char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);
    int i=0;
    if(ret_val)
    {
        while(st[i]!='\n' && st[i]!='\0')
        i++;
        if(st[i]=='\n')
        st[i]='\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}

void show_menu(void)
{
    printf("Please choose a function (q to quit):   a). Print array of string   b). Print array of string according to ASCII\n");
    printf("c). Print array of strings by length    d). Print array of strings by first string\n");
}
void display_orig(char string[][MAX], int num)
{
    for (int i=0; i<num; i++)
    puts(string[i]);
}
void display_array(char *string[], int num)
{
    for (int i=0; i<num; i++)
    puts(string[i]);
}

void display_array_ascii(char *string[], int num)
{
    char *temp;
    for (int top=0; top< num-1; top++)
    for (int seek = top +1; seek <num; seek++)
    if(strcmp(string[top], string[seek])>0)
    {
        temp = string[top];
        string[top] = string[seek];
        string[seek] = temp;
    }
    display_array(string, num);
}

void display_array_length(char *string[], int num)
{
    char *temp;
    for (int top=0; top< num-1; top++)
    for (int seek = top +1; seek <num; seek++)
    if(strlen(string[top])>strlen(string[seek]))
    {
        temp = string[top];
        string[top] = string[seek];
        string[seek] = temp;
    }
    display_array(string, num);
}

int first_letter(char *string)
{
    int ct=0;
    int i=0;
    while(isspace(string[i]))
    {
        i++;
        continue;
    }
    while(!isspace(string[i]))
    {
        ct++;
        i++;
    }
    return ct;
}

void display_array_first(char *string[], int num)
{
    char *temp;
    for (int top=0; top< num-1; top++)
    for (int seek = top +1; seek <num; seek++)
    if(first_letter(string[top])>first_letter(string[seek]))
    {
        temp = string[top];
        string[top] = string[seek];
        string[seek] = temp;
    }
    display_array(string, num);
}

