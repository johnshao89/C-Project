#include <stdio.h>

int main(void)
{
    char ch,last_ch;
    int i, k, j;
    printf("Please enter a capitalized letter: ");
    scanf("%c", &ch);
    for (i=0; i<=ch-'A';i++)
        {
            for (k=0;k<=i;last_ch = 'A'+k,k++)
                printf("%c",'A'+k); //print letter ascendingly
                //last_ch = 'A'+k to store
            for (j =1; j<=i; j++)
                printf("%c", last_ch-j); //print reversely
            printf("\n");               
        }
    return 0;
}