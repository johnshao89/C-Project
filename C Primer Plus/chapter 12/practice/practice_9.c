#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81

char *s_gets(char *st, int n);
int main(void)
{
    int words;
    char **pst;
    printf("How many words do you wish to enter? \n");
    scanf("%d", &words);
    pst = (char **)malloc(words*sizeof(char *));
    for(int i=0; i<words; i++)
    {
        char *temp = (char *)malloc(LEN * sizeof(char) );
        scanf("%s", temp);
        pst[i]=temp;
        free(temp);
    }
        printf("Here are your words:\n");
    for (int j=0; j<words;j++)
    {
        printf("%s", pst[j]);
    }
    free(pst);

}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find = '\0';
        else while (getchar()!='\n')
        continue;
    }
    return ret_val;
}