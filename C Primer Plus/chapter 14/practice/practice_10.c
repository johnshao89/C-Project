#include<stdio.h>
void showmenu(void);
int mod(int, int);
int addition(int, int);
int minus(int, int);
int multiply(int, int);

int main(void)
{
    int (*func[4])(int x, int y) ={mod,addition,minus,multiply};
    showmenu();
    char choice;
    choice = getchar();
    while(getchar()!='\n')
    continue;
    printf("%d\n",func[choice-'a'](10,10));
    return 0;
}

void showmenu(void)
{
    puts("Choose one of the following options:");
    puts("a) Plus   b) Minus");
    puts("c) Mod    d) Multiply");
}

int mod(int x, int y)
{
    return x%y;
}

int addition(int x, int y)
{
    return x+y;
}

int minus(int x, int y)
{
    return x-y;
}

int multiply(int x, int y)
{
    return x*y;
}