#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
    double base;
    int index;
    if(argc<3)
    puts("Sorry, need at least three arguments!");
    else
    {
        base = atof(argv[1]);
        index = atoi(argv[2]);
        printf("The answer is %lf.\n",pow(base, index));
    }
    puts("Done!");
    return 0;
}