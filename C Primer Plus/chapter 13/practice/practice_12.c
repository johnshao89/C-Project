#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ROW 20
#define COL 30
#define SLEN 81

int **array_gen(int row, int col);
void array_to_file(FILE *fp, int **array);
char *s_gets(char *st, int n);
int main(void)
{
    FILE *fp, *fa;
    int ch, count=0;
    char *filename = (char *)malloc(sizeof(char)*SLEN);
    int **data = array_gen(ROW,COL);
    printf("Enter the name of file:\n");
    s_gets(filename,SLEN);
    if ((fp =fopen(filename,"w+"))==NULL)
    {
        printf("Error in reading file.\n");
        exit(EXIT_FAILURE);
    }
    array_to_file(fp,data);
    /* The above code is for create 20 x 30 integer array in the file */
    rewind(fp);
    printf("Enter the target file to store:\n");
    s_gets(filename, SLEN);
    if( (fa =fopen(filename,"a+"))==NULL)
    {
        printf("Can not open target file.\n");
        exit(EXIT_FAILURE);
    }
    while( fscanf(fp, "%d", &ch)==1)
    {
        switch (ch)
        {
        case 0:
            putc(' ',fa);
            break;
        case 1:
            putc('.',fa);
            break;
        case 2:
            putc('\'',fa);
            break;
        case 3:
            putc(':',fa);
            break;
        case 4:
            putc('~',fa);
            break;
        case 5:
            putc('*',fa);
            break;
        case 6:
            putc('=',fa);
            break;
        case 7:
            putc('|',fa);
            break;
        case 8:
            putc('%',fa);
            break;
        case 9:
            putc('#',fa);
            break;
        }
        if(++count%30 ==0)
        putc('\n',fa);
    }
    fclose(fp);
    fclose(fa);
    free(filename);
    free(data);
    return 0;

}

int **array_gen(int row, int col)
{
    int **arr = (int **)malloc(sizeof(int*)*row);
    int i, j;
    srand(time(NULL));
    for(i =0; i<row; i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*col);
        for(j=0; j<col; j++)
            arr[i][j] = rand()%10;
    }
    return arr;
}

void array_to_file(FILE *fp, int **array)
{
    int i, j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        fprintf(fp,"%d ",array[i][j]);
        putc('\n',fp);
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
