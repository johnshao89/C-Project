#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81

char *s_gets(char *st, int n);

int main(void)
{
    char *filename = (char *)malloc(sizeof(char)*LEN);
    FILE *fs, *fa;
    int ch,count=1;
    printf("Enter the name of files;\nPress [ENTER] at new line to stop:\n");
    while(s_gets(filename, LEN-5)!=NULL && filename[0]!='\0')
    {   
        filename[LEN-5]='\0';
        if((fs = fopen(filename,"r"))==NULL)
        {
            printf("Can not open file.\nNext file please:\n");
            continue;
        }
        strcat(filename,".redo");
        if( (fa =fopen(filename, "w"))==NULL)
        {
            printf("Can not open file.\n");
            continue;
        }
        while((ch = getc(fs)) !=EOF)
        {
            if (count%3 ==0)
            putc(ch, fa);
            count++;
        }
        fclose(fs);
        printf("Enter next filename:\n");

    }
    rewind(fa);
    while((ch = getc(fa))!=EOF)
    putchar(ch);
    fclose(fa);
    free(filename);

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