#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[40];
    int i;
    for (i=0;i<40;i++)
    {
        if ((arr[i]=getchar())!='\n')
        continue;
        else break;
    }
    for (i=0; i<=strlen(arr);i++)
    printf("%c",arr[strlen(arr)-i]);
    return 0;

}