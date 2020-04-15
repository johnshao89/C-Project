#include <stdio.h>
#define SIZE 5

double diff(double array[], int n);

int main(void)
{
    double array[SIZE]= {1.1,2.2,5.5,4.4,2.3};
    printf("The difference between largest and smallest is %f.\n", diff(array, SIZE));
    return 0;
}

double diff(double array[], int n)
{
    int i;
    double largest, smallest;
    for(i=0, largest = *array, smallest = * array; i<n; i++)
    {
        if (largest < *(array+i))
        largest = *(array+i);
        if(smallest > *(array+i))
        smallest = *(array+i);
    }
    return (largest - smallest);
}