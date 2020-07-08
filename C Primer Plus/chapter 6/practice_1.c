#include <stdio.h>

int main(void)
{
    char array[26];
    int index;
    for (index =0; index <=25; index++)
    scanf("%c",&array[index]);
    for (index = 0; index <=25;index++)
    printf("%c", array[index]);
    return 0;
}