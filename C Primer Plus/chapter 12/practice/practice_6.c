#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SEED 10
int results[SEED];

int main(void)
{
    int i;
    srand((unsigned int)(time(0)));
    for (i=0; i<1000; i++)
    {
        switch (rand()%10+1)
        {
        case 1:
        results[0]++;
            break;
        case 2:
        results[1]++;
            break;
        case 3:
        results[2]++;
            break;
        case 4:
        results[3]++;
            break;
        case 5:
        results[4]++;
            break;
        case 6:
        results[5]++;
            break;
        case 7:
        results[6]++;
            break;
        case 8:
        results[7]++;
        break;
        case 9:
        results[8]++;
        break;
        case 10:
        results[9]++;
        break;        
        }
    }
    for (int i=0; i<SEED;i++)
    printf("%d \n", results[i]);
    return 0;
}