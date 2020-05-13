#include <stdio.h>
#include <string.h>
#include<math.h>

void copy_ptr (int n, double *source, double *target);

int main(void)
{
    double source[2][2] ={{1.1,2.2},{3.3, 4.4}};
    double target[2][2];
    for (int i =0; i<2; i++)
    copy_ptr(2, source[i], target[i]);
    for(int k =0; k<2; k++)
    {
        for (int j=0; j<2; j++)
        printf("%f ", target[k][j]);
        putchar('\n');
    }
    return 0;
}

void copy_ptr(int n, double *source, double *target) //when copy 2d array, only need to pass 1D array as address
{
    int i=0;
    for (i=0; i<n; i++)
    target[i] = source[i];
}