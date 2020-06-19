#include<stdio.h>
#include<ctype.h>
#define MAX 81

int main(int argc, char *argv[])
{
    int state =1;
    char mode='p';
    int ch;
    
    if(argc>2)
    {
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
        state =0;
    }
    else if (argc==2)
    {
        if(argv[1][0]!='-')
        {
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            state =0;
        }
        else
        {
            switch (argv[1][1])
            {
            case 'p':
            case 'u':
            case 'l': mode = argv[1][1]; break;
            default:
                printf("%s is invalid input.\n", argv[1]);
            }
        }
        
    }
    if (state)
    while((ch=getchar()!=EOF))
    {
        switch (mode)
        {
        case 'p':
            putchar(ch);
            break;
        case 'u':
            putchar(toupper(ch));
            break;
        case 'l':
            putchar(tolower(ch));
            break;
        }
    }

    return 0;

}