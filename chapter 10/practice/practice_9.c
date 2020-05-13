/*#include <stdio.h>
#define ROW 3
#define COL 5

void copy_prt(int n, int m, int VLA_source[n][m], int VLA_target[n][m]);
void print_vla(int n, int m, int vla[n][m]);

int main(void)
{
    int VLA_SOURCE[ROW][COL] ={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    int VLA_TARGET[ROW][COL];
    copy_prt(ROW, COL, VLA_SOURCE, VLA_TARGET);
    print_vla(ROW,COL,VLA_SOURCE);
    return 0;

}

void copy_prt(int n, int m, int VLA_source[n][m], int VLA_target[n][m])
{
    for (int i=0; i<n; i++)
    for (int j =0; j<m; j++)
    VLA_target[i][j]=VLA_source[i][j];
}

void print_vla(int n, int m, int vla[n][m])
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; i<m; j++)
        printf("%d ", vla[i][j]);
        printf("\n");
    }
}
*/
#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void display(int rows, int cols, double target[rows][cols], double source[rows][cols]);

int main(void)
{
	double source[ROWS][COLS] = {{1.1, 2.2, 3.3, 4.4, 5.5}, {6.6, 7.7, 8.8, 9.9, 10.10}, {11.11, 12.12, 13.13, 14.14, 15.15}};
	double target[ROWS][COLS];

	copy(ROWS, COLS, target, source);
	display(ROWS, COLS, target, source);

	return 0;
}

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    target[i][j] = source[i][j];
	    }
    }
}

void display(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    printf("Source array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    printf("%.2lf ", source[i][j]);
	    }
	    printf("\n");
    }
    printf("\n");

    printf("Target array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
	    {
		    printf("%.2lf ", target[i][j]);
	    }
	    printf("\n");
    }
}