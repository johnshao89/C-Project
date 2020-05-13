#include <stdio.h>
#define ROWS 3
#define COLS 5
void store_data(double source[][COLS]);
double row_mean(double source[][COLS], int row);
double mean_data(double source[][COLS]);
double max_data(double source[][COLS]);
void print_result(double source[][COLS]);

int main(void)
{
    double input[ROWS][COLS];
    store_data(input);
    print_result(input);
    return 0;
    
}

void store_data(double source[][COLS])
{
    printf("Please enter three sets of five double numbers:\n");
    printf("Please enter the first set:\n");
    for (int i =0; i<COLS; i++)
    scanf("%lf", source[0]+i);
    printf("Please enter the second set:\n");
    for (int j =0; j<COLS; j++)
    scanf("%lf", source[1]+j);
    printf("Please enter the thrid set:\n");
    for (int k =0; k<COLS; k++)
    scanf("%lf", source[2]+k);
}

double row_mean(double source[][COLS], int row)
{
    double row_sum =0;
    int index;
    for (index =0; index <COLS; index ++)
    row_sum +=source[row][index];
    return row_sum/index;
}

double mean_data(double source[][COLS])
{
    int i, j;
    double sum =0;
    for (i=0; i < ROWS; i++)
    for (j =0; j < COLS; j++)
    sum +=source[i][j];
    return sum/(ROWS*COLS);
}

double max_data(double source[][COLS])
{
    double max=source[0][0];
    int i, j;
    for (i=0; i<ROWS; i++)
    for (j = 0; j<COLS; j++)
    if (max<source[i][j])
    max = source[i][j];
    return max;

}

void print_result(double source[][COLS])
{
    for (int i=0; i<ROWS; i++)
    printf("The average of %d row is %lf.\n", i+1, row_mean(source, i));
    printf("The average of all values is : %lf.\n", mean_data(source));
    printf("The largest value among these values is :%lf.\n", max_data(source));
}
