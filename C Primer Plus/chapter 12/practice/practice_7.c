#include<stdlib.h>
#include"practice_7.h"

static int roll_dice(int sides)
{
    return rand()%sides +1;
}

int roll_n_dice(int dice, int sides)
{
    int i;
    int total =0;
    for (i=0; i<dice; i++)
    total+=roll_dice(sides);
    return total;
}