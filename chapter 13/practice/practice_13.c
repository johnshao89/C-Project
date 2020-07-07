//use VLA to finish practice 12
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define COL 30
#define ROW 20

static int array[ROW][COL];

void array_gen(int row, int col, int array[row][col]);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fp, *fa;
    array_gen(ROW,COL,array[ROW][COL]);
    


}

void array_gen(int row, int col, int array[row][col])
{
    int i,j;
    srand((unsigned int)(time(NULL)));
    for(i=0; i<row; i++)
    {
        for(j=0; j<col;j++)
        array[i][j]=rand()%10;
    }
}