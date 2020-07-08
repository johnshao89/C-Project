#include<stdio.h>
#define ROWS 3
#define COLS 5

void double_array(int row, int array[][COLS]);
void display(int row, int array[][COLS]);

int main(void)
{
    int orig_array[ROWS][COLS] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    double_array(ROWS, orig_array);
    display(ROWS, orig_array);
    return 0;
}

void double_array(int row, int array[][COLS])
{
    int i, j;
    for (i=0; i< row; i++)
    for (j=0; j<COLS; j++)
    array[i][j] *= 2;
}

void display(int row, int array[][COLS])
{
    for (int i=0; i<row;i++)
    {
        for (int j =0; j<COLS; j++)
        printf("%d ", array[i][j]);
        putchar('\n');
    }
}