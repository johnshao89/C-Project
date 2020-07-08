#include<stdio.h>
#include<stdlib.h>  //provide prototype for srand()
#include<time.h> //provide protopye for time()
#include "12_12_diceroll.h" // tell C to find head file in local disk
extern int roll_count;
int main(void)
{
    int status, dice, sides,roll;
    srand((unsigned int)time(0)); //shuffle the seed for rand()
    printf("Enter number of sides (0 to stop):\n");
    while (scanf("%d", &sides)==1 && sides!=0)
    {
        printf("Enter the number of dice:\n");
        if((status = (scanf("%d", &dice)))!=1)
        {
            if(status==EOF)
            break;
            else
            {
                printf("You should have entered an integer!\n");
                while(getchar()!='\n')
                continue;
                printf("How many sides?\n");
                continue;
            }
            
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled %d using %d %d-sides dice.\n", roll, dice, sides);
        printf("How many sides?\n");
    }
    printf("The rollem() has been called %d times.\n", roll_count);
    puts("Good bye!");
    return 0;
}

