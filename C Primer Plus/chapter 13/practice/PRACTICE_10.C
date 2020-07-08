#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 81
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fp;
    int ch;
    char *filename = (char *)malloc(sizeof(char)*LEN);
    unsigned long int pos;
    printf("Enter the filename to start:\n");
    while (s_gets(filename, LEN)!=NULL && (fp = fopen(filename, "r")) !=NULL)
    {
        printf("Enter the position (integer) to locate the start:\nPress negative or non-digital to stop.\n");
        if(scanf("%ld", &pos)==1 && pos>0)
        {
            while(getchar()!='\n')
            continue;
        }
        else break;
        fseek(fp, pos, SEEK_SET); //locate to the start of search
        while ((ch = getc(fp)) !='\n')
        putchar(ch);
        putchar('\n');
        fclose(fp);
        printf("Enter the next file please:\n");
    }
    printf("Done!");
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