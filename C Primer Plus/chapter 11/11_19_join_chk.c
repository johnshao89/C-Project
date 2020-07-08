#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] ="s smell like old shoes";
    int available;
    char bug[BUGSIZE];
    puts("What is your favourite flower?");
    s_gets(flower, SIZE);
    if (strlen(flower)+strlen(addon)+1<=SIZE)
    strcat(flower, addon);
    puts(flower);
    puts("What is your favourite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE-strlen(bug)-1;
    strncat(bug, addon, available);
    puts(bug);
    return 0;

}

char *s_gets(char *st, int n)
{
    int i=0;
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while(st[i]!='\n'&&st[i]!='\0')
        i++;
        if (st[i]=='\n')
        st[i]='\0';
        else
        {
            while (getchar()!='\n')
            continue;
        }
        
    }
    return ret_val;
}
