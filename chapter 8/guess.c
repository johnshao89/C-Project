#include <stdio.h>

int main(void)
{
    int guess = 1;
    char ch;
    printf("Pick an integer from 1 to 199. I will try to guess ");
    printf("it\nRespond with a y if my guess is right and with ");
    printf("\nan if it is wrong.\n");
    printf("Well, then, it is %d?\n", guess++);
    while ((ch=getchar())!='y')
    {
        if (ch == 'n')
        printf("Well, then, it is %d?\n", guess++);
        else
        printf("Sorry, I understand only y or n");
        while (getchar()!='\n')
        continue;
        
    }
    printf("I knew i could do it!\n");
    return 0;


}