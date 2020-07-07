/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    int ch;
    if(argc!=3)
    {
        printf("Usage: %s source_file, target_file.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if( (fa = fopen(argv[1], "r")) == NULL | (fs = fopen(argv[2], "w"))== NULL)
    {
        printf("Open files failed.\n");
        exit(EXIT_FAILURE);
    }
    while( (ch = getc(fs))!=EOF)
    putc(ch, fa);
    fclose(fa);
    fclose(fs);
    return 0;
    
}
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int byte;
    FILE * source;
    FILE * target;

    if (argc != 3)
    {
        printf("Usage: %s sourcefile targetfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((source = fopen(argv[1], "rb")) == NULL)
    {
        printf("Could not open file %s for input\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((target = fopen(argv[2], "wb")) == NULL)
    {
        printf("Could not open file %s for output\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((byte = getc(source)) != EOF)
    {
        putc(byte, target);
    }

    if (fclose(source) != 0)
        printf("Could not close file %s\n", argv[1]);

    if (fclose(target) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}