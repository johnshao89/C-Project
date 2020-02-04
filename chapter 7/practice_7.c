#include <stdio.h>
#define SIZE 40
#include <string.h>
int main(void)
{
    char ch[40],current_ch;
    int i=0;
    printf("Please enter a world or phrase: ");
    for (i =0; i<SIZE; i++)
        {
            if ((current_ch=getchar())!='\n')
            ch[i]=current_ch;
            else break;
        }
    for (i = 1; i<=strlen(ch); i++)
        {
            printf("%c", ch[strlen(ch)-i]);
        }
    printf("\n");
    return 0;
}