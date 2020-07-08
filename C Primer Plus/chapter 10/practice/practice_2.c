#include <stdio.h>

void copy_arr(double target[], double source[], int n);
void copy_ptr(double target[], double source[], int n);
void copy_ptrs(double target[], double source[], double f_source[]);
int main(void)
{
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5], target2[5], target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    int i;
    for (i=0; i<5; i++)
    printf("%f ", target1[i]);
    putchar('\n');
    for (i=0; i<5; i++)
    printf("%f ", target2[i]);
    putchar('\n');
    for (i=0; i<5; i++)
    printf("%f ", target3[i]);
    putchar('\n');
    return 0;
}

void copy_arr(double target[], double source[], int n)
{
    int i;
    for (i=0; i<n; i++)
    target[i] = source[i];
}

void copy_ptr(double target[], double source[], int n)
{
    int i;
    for (i =0; i< n; i++)
    *(target+i) = *(source + i);
}

void copy_ptrs(double target[], double source[], double f_source[])
{
    while (source < f_source)
    *(target++) = *(source++);
}