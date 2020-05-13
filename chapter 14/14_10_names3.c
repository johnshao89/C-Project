#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLEN 81

struct names{
    char *fname;
    char *lname;
    int letters;
};

void getinfo(struct names *);
void makeinfo(struct names *);
void showinfo(struct names *);
void cleanup(struct names *);
char *s_gets(char *st, int n);

int main(void)
{
    struct names person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}

void getinfo(struct names *pst)
{
    char temp[SLEN];
    printf("Enter your first name: \n");
    s_gets(temp, SLEN);
    pst->fname = (char *)malloc(strlen(temp)+1);
    strcpy(pst->fname, temp);
    printf("Enter your last name:\n");
    s_gets(temp, SLEN);
    pst->lname = (char *)malloc(strlen(temp)+1);
    strcpy(pst->lname, temp);

}

void makeinfo(struct names *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(struct names *pst)
{
    printf("%s %s, your name has %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct names *pst)
{
    free(pst->fname);
    free(pst->lname);
}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        *find = '\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}