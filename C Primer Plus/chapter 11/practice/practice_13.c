#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int index = 1;
    while(index <argc)
    {
        printf("%s ", argv[argc-index]);
        index ++;
    }
    puts("Done!");
    return 0;
}