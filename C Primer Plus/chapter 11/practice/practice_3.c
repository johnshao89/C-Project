#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 11

char *gets_letter(char *str);

int main(void)
{
    char input[MAX];
    char *output;
    puts("Enter a line:");
    output = gets_letter(input);
    if(output == NULL)
    puts("Input failed.");
    else 
    puts(output);
    puts("Done.");
    return 0;
}

char *gets_letter(char *str)
{
    char *ret_val = str;
    int ch;
    //skip the initial blank
    while((ch = getchar())!=EOF && isspace(ch))
    continue;
    if(ch ==EOF)
    return NULL;
    else 
    *str++ = ch;
    //get the rest of word
    while((ch = getchar())!=EOF && !isspace(ch))
    *str++ = ch;
    *str ='\0';  //use '\0' as the words end
    if (ch ==EOF)
    return NULL;
    else //encounter space after words
    {
        while(ch !='\n')
        ch = getchar();
        return ret_val;
    }
    

}