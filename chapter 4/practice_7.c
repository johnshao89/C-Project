#include <stdio.h>
#include <float.h>

int main(void)
{
    double num_1 = 1.0/3.0;
    float num_2 = 1.0/3.0;
    printf("%.6f\n%.12f\n%.17f\n", num_1,num_1,num_1);
    printf("%.6f\n%.12f\n%.17f\n", num_2,num_2,num_2);
    printf("float digits %d\n", FLT_DIG);
    printf("double digits %d\n",DBL_DIG);
    return 0;
}