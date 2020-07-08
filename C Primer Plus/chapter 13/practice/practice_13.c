//use VLA to finish practice 12
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define COL 30
#define ROW 20
#define LEN 81

static int array[ROW][COL];

void array_gen(int row, int col, int array[row][col]);
char transform[11] = " .':~*=|%#";
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fp;
    char *filename = (char *)malloc(sizeof(char)*LEN);
    array_gen(ROW,COL,array);
    printf("Enter the target file:\n");
    s_gets(filename, LEN);
    if( (fp = fopen(filename, "w"))==NULL)
    {
        printf("Can not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<ROW;i++)
    {
        for(int j =0; j<COL;j++)
        putc(transform[array[i][j]],fp);
        putc('\n',fp);
    }
    fclose(fp);
    free(filename);
    return 0;
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

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find = '\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}