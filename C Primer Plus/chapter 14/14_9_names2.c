#include<stdio.h>
#include<string.h>
#define LEN 30
struct namect{
    char first[LEN];
    char last[LEN];
    int letters;
};
char *s_gets(char *st, int n);
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void)
{
    struct namect person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);
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
        else while (getchar()!='\n')
        continue;
    }
    return ret_val;
}
struct namect getinfo(void)
{
    struct namect temp;
    printf("Enter first name:");
    s_gets(temp.first, LEN);
    printf("Enter last name: ");
    s_gets(temp.last,LEN);
    return temp;
}

struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.first)+strlen(info.last);
    return info;
}

void showinfo(struct namect info)
{
    printf("%s %s, your name has %d letters.\n", info.first, info.last, info.letters);
}
