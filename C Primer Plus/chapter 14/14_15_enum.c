#include <stdio.h>
#include<string.h>
#include<stdbool.h>
enum spectrum {
    red, orange, yellow, green, blue, violet
};

const char *colors[] = {"red","orange","yellow","green","blue","violet"};

#define LEN 30

char *s_gets(char *st, int n);
int main(void)
{
    char choice[LEN];
    enum spectrum color;
    puts("Enter your color: ");
    puts("Empty line to stop ");
    bool color_is_found = false;
    while(s_gets(choice, LEN)!=NULL && choice[0]!='\0')
    {
        for (color = red; color <=violet; color++)
        {
            if(strcmp(choice, colors[color])==0)
            {
                color_is_found = true;
                break;
            }
        }
        if(color_is_found)
        switch (color)
        {
        case red: puts("Roses are red!");
            break;
        case orange: puts("Orange is organe");
            break;
        case yellow: puts("The river is yellow");
            break;
        default:
            break;
        }
        else
        printf("I do not know about %s.\n",choice);        
        color_is_found=false;
        puts("Next color, please");
    }
    puts("Done.");
    return 0;

}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else
        {
            while(getchar()!='\n')
            continue;
        }
        
    }
    return ret_val;
}