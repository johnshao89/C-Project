#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *target);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    int index;
    int ch;
    if (argc <3)
    {
        printf("Usage: %s target_name source_name1 source_name2 ... source_namen", argv[0]);
        exit(EXIT_FAILURE);
    }

    if( (fa =fopen(argv[1],"a+"))==NULL)
    {
        printf("Can not open target file.\n");
        exit(EXIT_FAILURE);
    }
    if( setvbuf(fa, NULL, _IOFBF, BUFSIZE)!=0)
    {
        printf("Create buffer failed.\n");
        exit(EXIT_FAILURE);
    }
    for(index =2; index <argc; index++)
    {
        if(strcmp(argv[1], argv[index])==0)
        {
            printf("Can not append to itself.\n");
            continue;
        }
        if( (fs = fopen(argv[index],"r")) ==NULL)
        {
            printf("Can not open %s.\n", argv[index]);
            continue;
        }
        if(setvbuf(fs, NULL, _IOFBF, BUFSIZE)!=0)
        {
            printf("Can not create output buffer.\n");
            continue;
        }
        append(fs, fa);
        if(ferror(fs)!=0)
        printf("Error in reading files.\n");
        if(ferror(fa)!=0)
        printf("Error in writing files.\n");
        fclose(fs);
    }
    printf("Done appending.\n");
    rewind(fa);
    while( (ch = getc(fa))!=EOF)
    putchar(ch);
    fclose(fa);
    printf("Success!\n");
    return 0;
}

void append(FILE *source, FILE *target)
{
    size_t bytes;
    char *temp = (char*)malloc(sizeof(char)*BUFSIZE);
    while((bytes = fread(temp, sizeof(char), BUFSIZE, source))>0)
        fwrite(temp, sizeof(char),bytes,target);
    free(temp);

}
