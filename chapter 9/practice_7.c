#include <stdio.h>
#include <ctype.h>

int char_report(char ch);

int main(void)
{
    char ch;
    printf("Enter a series of characters: ");
    while ((ch=getchar())!=EOF)
    {
        if(char_report(ch)==-1 && ch!='\n')
            printf("%c is not a letter.\n",ch);
        else if (char_report(ch)==-1 && ch=='\n')
            printf("Please enter your letters: ");
        else
            printf("%c is a letter and its position is %d.\n",ch,char_report(ch));
                
    }
    printf("Done!\n");
    return 0;
}

int char_report(char ch)
{
    if(isalpha(ch))
    {
        //if(isupper(ch))
        return ch;
        //else return ch-96;
    }
    else
        return -1;   
}

