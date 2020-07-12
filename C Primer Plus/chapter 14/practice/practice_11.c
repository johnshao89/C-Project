#include<math.h>
#include<stdio.h>
#include<string.h>
#define LEN 10
void transform(double[],double[],int, double (*func)(double));

int main(void)
{
    double source[LEN];
    for(int i=0;i<LEN;i++)
    source[i]=1/(i+1.0);
    double target[LEN];
    transform(source, target,LEN,sin);
    for(int i=0;i<LEN;i++)
    printf("%.2f\n",target[i]);
    return 0;

}

void transform(double source[], double target[],int n, double (*func)(double num))
{
    int i;
    for(i=0;i<n;i++)
    target[i] = func(source[i]);
}