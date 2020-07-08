#include <stdio.h>
#define LEN 4

void sum_array(int source1[], int source2[], int target[], int n);
void display(int array[], int n);

int main(void)
{
    int source1[LEN] ={2,4,5,8};
    int source2[LEN] ={1,0,4,6};
    int target[LEN];
    sum_array(source1, source2, target, LEN);
    display(target, LEN);
    return 0;

}

void sum_array(int source1[], int source2[], int target[], int n)
{
    for (int i=0; i<n; i++)
    target[i] = source1[i] + source2[i];
}

void display(int array[], int n)
{
    for (int i =0; i<n; i++)
    printf("%d ", array[i]);
}