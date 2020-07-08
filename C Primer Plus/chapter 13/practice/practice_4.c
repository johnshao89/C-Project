#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int index;
    FILE *fp;
    int ch;
    for(index =1;index<=argc;index++)
    {
        if ((fp = fopen(argv[index],"r")) == NULL)
        {
            printf("Can not open file %s.\n", argv[index]);
            exit(EXIT_FAILURE);
        }
        while( (ch = getc(fp)) != EOF)
        putc(ch, stdout);
        fclose(fp);
    }
    return 0;
}