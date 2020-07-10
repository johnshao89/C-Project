#include<stdio.h>
#include<string.h>
#define LEN 30
struct namect{
    char first[LEN];
    char last[LEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(struct namect*);
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    return 0;
}

void getinfo(struct namect *pst)
{
    printf("Enter your first name: ");
    s_gets(pst->first, LEN);
    printf("Enter your last name: ");
    s_gets(pst->last, LEN);
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->first) + strlen(pst->last);
}

void showinfo(struct namect *pst)
{
    printf("%s %s, your name has %d letters.\n", pst->first, pst->last, pst->letters);
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
        else while (getchar()!='\n')
        continue;
    }
    return ret_val;
}