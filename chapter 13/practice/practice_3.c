#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define LEN 41

char *s_gets(char *st, int n);

int main(void)
{
    char *filename = (char*)malloc(sizeof(char)*LEN);
    FILE *fp;
    int ch;
    printf("Enter the filename:\n");
    s_gets(filename, LEN);
    if ((fp = fopen(filename, "r+"))==NULL)
    {
        printf("Can not open %s file.\n", filename);
        exit(EXIT_FAILURE);
    }
    while( (ch = getc(fp)) !=EOF)
        {
            ch = toupper(ch);
            putc(ch, fp);
        }
    fclose(fp);
    free(filename);
    return 0;
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