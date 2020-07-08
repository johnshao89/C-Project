// modify the addaword.c program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 81
char *s_gets(char *st, int n);
int main(void)
{
    FILE *fp;
    int letter_index=0;
    char *words = (char*)malloc(sizeof(char)*LEN);
    char *filename = (char *)malloc(sizeof(char)*LEN);
    fprintf(stdout, "Please enter the file name to open:\n");
    s_gets(filename, LEN);
    if( (fp = fopen(filename, "a+"))==NULL)
    {
        fprintf(stderr, "Can not open %s file.\n", filename);
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    while(fgets(words, LEN, fp)!=NULL)
    {
        letter_index++;
    }
    rewind(fp);
    fprintf(stdout, "Enter a word to be added:\nPress # at the line start to end\n");
    while(fscanf(stdin, "%s", words)==1 && words[0]!='#')
    {
        fprintf(fp,"%d : %s\n",++letter_index,words);
        fprintf(stdout,"Enter the next word:\n");
    }
    fclose(fp);
    free(words);
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