#include <stdio.h>
#define COLS 4

int sum2d(const int ar[][COLS], int rows);
int sum(const int ar[], int n);

int main(void)
{
    int total1, total2, total3;
    int *pt1;
    int(*pt2)[COLS];
    pt1 = (int[2]){10,20};
    pt2 = (int[2][COLS]){{1,2,3,-9},{4,5,6,-8}};
    total1 = sum(pt1, 2);
    total2 = sum2d(pt2, 2);
    total3 = sum((int []){4,4,4,5,5,5},6);
    printf("Total1 = %d\n",total1);
    printf("total2 = %d\n", total2);
    printf("Total3 = %d\n", total3);
    return 0;
}

int sum2d(const int ar[][COLS],int rows)
{
    int i,c;  
    int tot=0;
    for (i=0; i<rows; i++)
    for (c=0; c<COLS; c++)
    tot+=ar[i][c];
    return tot;
}

int sum(const int ar[], int n)
{
    int i;
    int tot=0;
    for (i=0; i<n; i++)
    tot+=ar[i];
    return tot;
}