#include <stdio.h>
#define LINES 6
int main(void)
{
    int i, k, current_char='A';
    for (i=1; i<=LINES; i++)
        {
            for (k=0; k<i; current_char++,k++)
            printf("%c",current_char);
            printf("\n");
        }
    return 0;
}