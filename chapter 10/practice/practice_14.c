#include <stdio.h>
#define ROWS 3
#define COLS 5

void store_data(int row, int col, double source[row][col]);
double row_mean(double *array1d);
double average(int row, int col, double source[row][col]);
double max(int row, int col, double source[row][col]);
void print_result(int row, int col, double source[row][col]);

int main(void)
{
    double input[ROWS][COLS];
    store_data(ROWS, COLS, input);
    print_result(ROWS, COLS, input);
    return 0;
}

void store_data(int row, int col, double source[row][col])
{
    int i,j;
    for (i=0; i< row; i++)
    {
        printf("Please enter the %d line of data: \n", i+1);
        for (j =0; j< col; j++)
        scanf("%lf", &source[i][j]);
    }
}

double row_mean(double *array1d)
{
    double row_sum=0;
    int c;
    for(c =0; c<COLS; c++)
    row_sum +=array1d[c];
    return row_sum/COLS;
}

double average(int row, int col, double source[row][col])
{
    double sum=0;
    int i, j;
    for (i=0; i<row; i++)
    for (j =0; j<col;j++)
    sum +=source[i][j];
    return sum/(ROWS*COLS);
}

double max(int row, int col, double source[row][col])
{
    double max = source[0][0];
    int i, j;
    for (i=0; i<row; i++)
    for (j =0; j<col; j++)
    if (max<source[i][j])
    max = source[i][j];
    return max;
}

void print_result(int row, int col, double source[row][col])
{
    int index;
    for (index =0; index <row; index++)
    printf("The average of %d line is %lf.\n", index +1, row_mean(source[index]));
    printf("The average of data set is %lf.\n", average(ROWS, COLS, source));
    printf("The max of the data set is %lf.\n", max(ROWS, COLS, source));
}