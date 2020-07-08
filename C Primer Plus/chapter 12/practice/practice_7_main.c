#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "practice_7.h"

int main(void)
{
    int num_set;
    int sides, dice;
    int i;
    int *pt;
    puts("Enter the number of sets; enter q to stop: ");
    while(scanf("%d", &num_set)==1 && num_set!='q')
    {
        pt = (int *)malloc(num_set*sizeof(int));
        puts("How many sides and how many dice?");
        srand((unsigned int)(time(0)));
        if(scanf("%d %d", &sides, &dice)==2)
        {
            for(i=0;i<num_set;i++)
            pt[i]=roll_n_dice(dice, sides);            
        }
        printf("Here are %d sets of %d %d-sided throws.\n", num_set, dice, sides);
        for(int k=1; k<=num_set;k++)
        {
            printf("%d ", pt[k-1]);
            if(k%15==0)
            printf("\n");
        }
        printf("\nHow many sets? Enter q to stop:");
        free(pt);
    }
    return 0;
}