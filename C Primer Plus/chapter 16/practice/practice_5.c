#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define NUM 49
void lottery(int ar[], int size, int num);
void array_gen(int *);
int main(void)
{
    int array[49];
    char ch;
    array_gen(array);
    do
    {
        lottery(array,NUM,6);
        printf("Again?<y/n>");
        ch = getchar();
        while(getchar()!='\n')
        continue;
    } while (ch!='n');
    

    return 0;
}

void array_gen(int *ar)
{
    int i;
    for(i=1;i<=NUM;i++)
    ar[i-1]=i;
}

void lottery(int ar[], int size, int num)
{
    srand((unsigned int)time(0));
    int i,choice, result[num], temp;
    for(i=0;i<num;i++)
    {
        choice = rand()%size;
        temp = ar[choice];
        printf("%d ", temp);
        ar[choice]=ar[size-1];
        ar[size-1]=temp;
        size--;        
    }
}