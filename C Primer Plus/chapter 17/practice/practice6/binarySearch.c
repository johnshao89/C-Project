#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int binarySearch(int *arr, int size, int target);

int main(void)
{
    int arrTest[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("%d", binarySearch(arrTest,10,11));
    return 0;
}

int binarySearch(int *arr, int size, int target)
{
    int first =0;
    int last = size-1;
    int middle;
    int isFound = 0;
    while(first<last)
    {
        middle = first + (last-first)/2;
        if(arr[middle]>target)
        last = middle-1;
        else if(arr[middle]<target)
        first = middle+1;
        else {
            isFound = 1;
            break;
        }
    }
    if(arr[0] == target)
    isFound = 1;
    return isFound;    
}