#include<stdio.h>
#include<string.h>
#define MAX 81
int is_within(char *str, char ch);

int main(void)
{
    char input[MAX];
    char ch;
    char *output;
    puts("Enter a string:");
    while(fgets(input, MAX, stdin))
    {
        puts("Enter a character:");
        scanf("%c",&ch);
        while(getchar()!='\n')
        continue;
        printf("%d\n", is_within(input, ch));
        puts("Enter another string:");
    }
    puts("Done!");
    return 0;
}

int is_within(char *str, char ch)
{
    /*while(*str!=EOF && *str !=ch)
    {
        str++;
        continue;
    }
    if(*str == ch)
    return 1;
    return 0;*/
    for (int i=0; i<strlen(str); i++)
    {
        if(str[i]==ch)
        return 1;
    }
    return 0;
}
