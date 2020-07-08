#include <stdio.h>
#include<stdlib.h>
#define ARSIZE 1000

int main(void)
{
    double numbers[ARSIZE];
    double value;
    int i;
    const char *file ="number.dat";
    long pos;
    FILE *iofile;
    for (i=0; i< ARSIZE; i++)
    numbers[i] = 100.0*i + 1.0/(i+1);
    if ((iofile =fopen(file, "wb"))== NULL)
    {
        fprintf(stderr, "Can not open %s file \n",file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb"))==NULL)
    {
        fprintf(stderr, "Can not open %s file\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter an index from 0 to %d: \n", ARSIZE-1);
    while ((scanf("%d", &i))==1 && i < ARSIZE)
    {
        pos = (long)i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value,sizeof(double),1, iofile);
        printf("The value is %lf\n",value);
    }
    fclose(iofile);
    puts("Bye");
    return 0;

}