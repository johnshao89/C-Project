#include <stdio.h>
#define SIZE 5

int n_index(double array[], int n);

int main(void)
{
    double array[SIZE] = {1.1,2.2,5.5,4.4, 2.3};
    int index;
    index = n_index(array,SIZE);
    printf("The largest number has an index of %d.\n",index);
    return 0;
}

int n_index(double array[], int n)
{
    int i, index;
    double largest;
    for (i=0, largest = *array; i<n; i++)
    {
        if (largest<*(array+i))
        {
            largest = *(array + i);
            index = i;
        }
    }
    return index;
}