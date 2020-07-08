#include <stdio.h>
#define SIZE 5

void sort_desc(double array[], int n);

int main(void)
{
    double array[SIZE] = {1.1,3.3,2.2,7.5,4.3};
    sort_desc(array, SIZE);
    for (int i =0; i< SIZE; i++)
    printf("%f ", *(array+i));
    putchar('\n');
    return 0;
}

void sort_desc(double array[], int n)
{
    double temp;
    int i;
    int j;
    for (i=0; i<n; i++)
        for(j =i+1; j<n; j++)
        {
            if (*(array+i)>*(array+j))
            {
                temp = *(array+i);
                *(array+i) = *(array +j);
                *(array+j)= temp;
            }
        }
}