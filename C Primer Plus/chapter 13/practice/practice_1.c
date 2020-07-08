#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 41

char *s_gets(char *st, int n);

int main(void)
{
    FILE *fp, *rfp;
    char filename[LEN];
    char *content;
    int ch;
    printf("Enter the file name:\n");
    s_gets(filename, LEN);
    if( (fp = fopen(filename,"w"))==NULL)
    {
        printf("Can not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    content = (char*)malloc(LEN*sizeof(char));
    printf("Enter the content you want to type:\n");
    s_gets(content, LEN);
    fprintf(fp, "%s\n", content);
    fclose(fp);
    rfp = fopen(filename, "r");
    while( (ch = getc(rfp)) !=EOF)
    putchar(ch);
    fclose(rfp);
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