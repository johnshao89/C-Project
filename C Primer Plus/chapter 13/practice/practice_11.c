#include<stdio.h>
#include<string.h>
#define MAXLEN 256
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *line = (char *)malloc(sizeof(char)*MAXLEN);
    if(argc!=3)
    {
        printf("Usage: %s letter filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line,MAXLEN,fp)!=NULL)
    {
        if(strchr(line,argv[1][0])!=NULL);
        fputs(line, stdout);
    }
    printf("Done!");
    free(line);
    fclose(fp);
    return 0;

}