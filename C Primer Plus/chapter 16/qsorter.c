#include<stdio.h>
#include<stdlib.h>
#define NUM 40

void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void *p1, const void *p2);

int main(void)
{
    double array[NUM];
    fillarray(array, NUM);
    puts("List generated:");
    showarray(array, NUM);
    qsort(array, NUM, sizeof(double), mycomp);
    puts("\nSorted list:");
    showarray(array, NUM);
    return 0;
}

void fillarray(double ar[], int n)
{
    int index;
    for(index=0; index<n;index++)
    {
        ar[index] = (double)rand()/ ((double)rand()+0.1);
    }
}

void showarray(double ar[], int n)
{
    int index;
    for(index=0; index<n; index++)
    {
        printf("%9.4f", ar[index]);
        if(index%6 ==5)
        putchar('\n');
    }
    
}

int mycomp(const void *p1, const void *p2)
{
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;
    if(*a1<*a2)
    return 1;
    else if (*a1==*a2)
    return 0;
    else return -1;
}