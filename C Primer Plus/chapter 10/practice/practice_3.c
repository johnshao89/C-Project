#include <stdio.h>
#define SIZE 5
int max(int arr[], int n);

int main(void)
{
    int array[SIZE] = {1,2,3,4,5};
    int max_num;
    max_num = max(array, SIZE);
    printf("The max number is %d, arr[0] is %d.\n", max_num, array[0]);
    return 0;

}

int max(int arr[], int n)
{
    int largest = *arr;
    int i;
    for (i=0; i<n; i++)
    {
        if (largest <*(arr+i))
        largest = *(arr+i);
    }
    return largest;
}