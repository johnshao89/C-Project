#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"

int roll_count =0;

static int rollem(int sides)
{
    int roll;
    roll = rand()%sides + 1;
    return roll;
}

int roll_n_dice(int sides, int dice)
{
    int total =0;
    int i;
    if(dice<1)
        {
            printf("At least one dice.");
            return -1;
        }
    if (sides<2)
        {
            printf("At lease two sides.");
            return -2;
        }
    for (i=0;i<dice;i++)
    total+=rollem(sides);
    return total;
}