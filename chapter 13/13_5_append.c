#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fa, *fs; //define source file and append file
    char file_app[SLEN]; //define append file name
    char file_src[SLEN]; //define source file name
    int ch, files;
    puts("Enter name of the destination:");
    s_gets(file_app, SLEN);
    if ( (fa = fopen(file_app, "a++")) == NULL )
    {
        fprintf(stderr,"Can not open % file\n",file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFFSIZE)!=0)
    {
        fprintf(stderr, "Can not create output buff\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter the name of source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp (file_src, file_app)==0)
        fprintf(stderr, "Can not append to itself\n");
        else if ((fs = fopen(file_src,"r"))==NULL)
        fprintf(stderr, "Can not read %s file \n", file_src);
        else
        {
            if(setvbuf(fs, NULL, _IOFBF, BUFFSIZE)!=0)
            {fprintf(stderr, "Can not create input buff\n");
            continue;}
            append(fs, fa);
            if (ferror(fs)!=0)
            fprintf(stderr,"Error in writting file %s \n", file_app);
            fclose(fs);
            files++;
            printf("Files %s appended\n", file_src);
            puts("next line (empty to quit)");
        }       
    }
    printf("Done appending!\n");
    rewind(fa);
    printf("%s contents:\n",file_app);
    while((ch = getc(fa))!=EOF)
    putchar(ch);
    puts("Done display.");
    fclose(fa);
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFFSIZE];
    while ((bytes = fread(temp, sizeof(char),BUFFSIZE,source)) >0)
    fwrite(temp, sizeof(char), BUFFSIZE, dest);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else 
        while (getchar()!='\n')
        continue;
    }
    return ret_val;
}