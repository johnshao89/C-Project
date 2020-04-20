#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main(void)
{
    FILE *fp;
    char words[MAX];
    if ((fp=fopen("wordy","a+"))==NULL)
        {
        fprintf(stdout,"Can not open \"wordy\" file\n");
        exit(EXIT_FAILURE);
        }
    puts("Enter your words and type # at the beginning to terminate");
    while ((fscanf(stdin,"%40s",words)==1) && (words[0]!='#'))
    fprintf(fp,"%s\n", words);
    puts("File content:");
    rewind(fp);
    while(fscanf(fp,"%s", words)==1)
    puts(words);
    puts("Done!");
    if(fclose(fp)!=0)
    fprintf(stderr, "File close failure\n");
    return 0;
}