#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
    char ch;
    int i,j;
    printf("Enter a character: ");
    ch = getchar();
    getchar();
    printf("Enter number of lines and cols: ");
    scanf("%d %d.\n",&i, &j);
    chline(ch,i,j);
    return 0;
}

void chline(char ch, int i, int j)
{
    int col, row;
    for (col = 1; col<=i; col++)
    {
        for (row =1; row<=j;row++)
        putchar(ch);
        putchar('\n');
    }

}