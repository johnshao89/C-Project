#include<stdio.h>
#include<string.h>
void select_copy(int source[], int target[], int number);

int main(void)
{
    int start =3;
    int end = 5;
    int source[10] = {1,2,3,4,5,6,7,8,9,10};
    int target[3];
    select_copy(&source[2], target, 3);
    for (int i =0; i<3;i++)
    printf("%d ",target[i]);
    return 0;

}

void select_copy(int source[], int target[], int number)
{
    for (int i =0; i<number;i++)
    target[i] = source[i];
}