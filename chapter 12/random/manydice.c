#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"
#include <time.h>

int main(void)
{
    int dice, side, roll, status;
    srand((unsigned int)(time(0))); //shuffle the seed for rand()
    printf("Enter the sides: \n");
    while(scanf("%d",&side)==1 && side>1)
    {
        printf("How many dices? \n");
        if((status = scanf("%d",&dice))!=1)
            {
                if (status ==EOF)
                break;
                else
                {
                    printf("You should have entered an integer!\n");
                    printf("Begin again!\n");
                    while(getchar()!='\n')
                    continue;
                    printf("How many sides?\n");
                    continue;
                }
                
            }
        roll = roll_n_dice(side, dice);
        printf("You have rolled %d using %d sides and %d dices.\n",roll, side, dice);
        printf("How many dices? \n");
    }
    printf("The rollem has been called %d times.\n", roll_count);
    return 0;
}