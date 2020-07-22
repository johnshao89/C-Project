#include<stdio.h>
#define HARM_MEAN(X,Y) ((1.0/(X) + 1.0/(Y))/2.0)

int main(void)
{
    int x, y;
    printf("Enter a pair of integers:");
    while(scanf("%d %d", &x, &y)==2)
    {
        printf("%f\n", HARM_MEAN(x,y));
        printf("Enter the next pair:\n");
    }
    return 0;
}
