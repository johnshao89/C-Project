#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(char argc, char *argv[])
{
    FILE *fp;
    int i; // loop through the files//store the argv[1] value
    int count=0; // count the letter times in file
    int ch; // read the letter from files
    if(argc <3)
    {
        printf("Usage: %s letter filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i =2; i<argc; i++)
    {
        if( (fp =fopen(argv[i],"r"))==NULL)
        {
            printf("Can not open %s file.\n", argv[i]);
            continue;
        }
        while( (ch = getc(fp)) !=EOF)
        {
            if (ch == argv[1][0])
            count++;
        }
        printf("The file %s has %d-%c letter.\n", argv[i], count, argv[1][0]);
        fclose(fp);
    }
    printf("Done!");
    return 0;
}