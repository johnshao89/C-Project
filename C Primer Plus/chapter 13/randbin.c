#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARSIZE 1000

int main(void)
{
    double numbers[ARSIZE];
    int i;
    int index;
    double num;
    long unsigned int offset;
    const char *file ="numbers.dat";
    FILE *fp, *iofp;
    for (i=0; i<1000; i++)
    numbers[i] = 100.0*i + 1.0/(1+i);
    if( (fp = fopen(file, "wb"))==NULL)
    {
        printf("Can not open file.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&numbers, sizeof(double), ARSIZE, fp);
    fclose(fp);
    if( (iofp = fopen(file, "rb"))==NULL)
    {
        printf("Can not read file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter an index to search:");
    scanf("%d", &index);
    while(getchar()!='\n')
    continue;
    offset = (long)index*sizeof(double);
    fseek(iofp, offset, SEEK_SET);
    fread(&num, sizeof(double), 1, iofp);
    printf("The value at index %d is %lf.\n", index, num);
    fclose(iofp);
    return 0;
}