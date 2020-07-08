#include <stdio.h>
#define LINES 6

int main(void)
{
    int i, k, ch=65+LINES;
    for (i=1; i<=LINES; i++)
        {
            for (k=1; k<=i; k++)
                printf("%c",ch-k);
            printf("\n");
        }
    return 0;
}