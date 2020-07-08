#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define ROW 20
#define COL 30
#define LEN 81

int **array_gen(int row, int col);
static char transform[11] = " .':~*=|%#";
char *s_gets(char *st, int n);
void trans_array(int **array);

int main(void)
{
    FILE *fp;
    char *filename = (char*)malloc(sizeof(char)*LEN);
    printf("Enter the filename to store original data:\n");
    s_gets(filename, LEN);
    if( (fp = fopen(filename, "w")) == NULL)
    {
        printf("Can not open file.\n");
        exit(EXIT_FAILURE);
    }
    int **array = array_gen(ROW,COL);
    for (int i=0; i<ROW; i++)
    {
        for (int j =0; j<COL; j++)
        fprintf(fp,"%d ",array[i][j]);
        putc('\n',fp);
    }
    trans_array(array);
    for(int i=0; i<ROW;i++)
    {
        for(int j=0; j<COL; j++)
        printf("%d ",array[i][j]);
        putchar('\n');
    }
    fclose(fp);
    free(filename);
    free(array);
    return 0;
    
    

}

int **array_gen(int row, int col)
{
    int **array = (int **)malloc(sizeof(int*)*row);
    int i, j;
    srand((unsigned int)(time(NULL)));
    for(i=0;i<ROW;i++)
    {
        array[i] = (int *)malloc(sizeof(int)*COL);
        for(j=0;j<COL;j++)
        array[i][j] = rand()%10;
    }
    return array;
}

void trans_array(int **array)
{
    int i,j;
    for (i=1;i<ROW-1;i++)
    for (j=1; j<COL-1;j++)
    {
        if(fabs(array[i][j]-array[i][j-1])>1 && fabs(array[i][j]-array[i][j+1])>1 && fabs(array[i][j]-array[i-1][j])>1 && fabs(array[i][j]-array[i+1][j])>1)
        array[i][j] = (array[i][j-1] + array[i][j+1] + array[i-1][j] + array[i+1][j])/4;
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