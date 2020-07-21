#ifndef NAMES_ST_H
#define NAMES_ST_H
#include<string.h>
#define SLEN 32

struct names_st{
    char first[SLEN];
    char last[SLEN];
};

typedef struct names_st names;

void get_names(names *);
void show_names(const names*);
char *s_gets(char *st, int n);
#endif