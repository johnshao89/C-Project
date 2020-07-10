#include<stdio.h>
#include<stdlib.h>

struct flex{
    size_t count;
    double average;
    double scores[]; // flexbile array member
};

void showFlex(const struct flex *p);

int main(void)
{
    int n=5;
    int i;
    int tot=0;
    struct flex *pf1, *pf2;
    pf1 = (struct flex*)malloc(sizeof(struct flex)+n*sizeof(double));
    pf1->count = n;
    for(i=0;i<n;i++)
    {
        pf1->scores[i] = 20.0-i;
        tot+=pf1->scores[i];
    }
        pf1->average = tot/pf1->count;
    showFlex(pf1);
    n =9;
    tot =0;
    pf2 = (struct flex *)malloc(sizeof(struct flex)+n*sizeof(double));
    pf2->count = n;
    for(i=0;i<n;i++)
    {
        pf2->scores[i]=20-i/2.0;
        tot+=pf2->scores[i];
    }
    pf2->average = tot/pf2->count;
    showFlex(pf2);
    free(pf1);
    free(pf2);
    return 0;
}

void showFlex(const struct flex *p)
{
    int i;
    printf("Scores: ");
    for(i=0;i<p->count;i++)
    printf("%g ", p->scores[i]);
}