#include <stdio.h>
#define MONTHS 12
#define YEARS 5
void Year_Average(const float source[][MONTHS], int n);
void Month_Average(const float source[][MONTHS], int n);
int main(void)
{
    const float rain[YEARS][MONTHS]={
        {4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7,4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    Year_Average(rain, YEARS);
    Month_Average(rain, YEARS);
    return 0;


}

void Year_Average(const float source[][MONTHS], int n)
{
    float year_sum=0;
    int i,j;
    for (i =0; i< n; i++)
        {
            for (j =0; j< MONTHS; j++)
            year_sum += source[i][j];
            printf("The average of year %d is %.2f.\n", 2010+i, year_sum/j);
        }
}

void Month_Average(const float source[][MONTHS], int n)
{
    float month_sum = 0;
    int i, j;
    for (i =0; i<MONTHS; i++)
    {
        for (j =0; j<n; j++)
        month_sum += source[j][i];
        printf("The %d month average is %.2f.\n", i+1, month_sum/j);
    }
}