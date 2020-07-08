#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char*argv[])
{
    FILE *f1, *f2;
    int ch1, ch2;
    int state1=1, state2=1; //set the f1, f2 state. 1 for unfinished reading, 0 for finished reading
    if(argc !=3)
    {
        printf("Usage: %s file1 file2.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if( (f1=fopen(argv[1], "r"))==NULL ||((f2 = fopen(argv[2], "r"))==NULL))
    {
        printf("Can not open files.\n");
        exit(EXIT_FAILURE);
    }
    ch1 = getc(f1);
    ch2 = getc(f2);
    while(ch1!=EOF ||ch2!=EOF) // terminate loop when both files have been read
    {   
                while(ch1!='\n' && ch1!=EOF) // if ch1 did not reach line end
                {
                    putchar(ch1); //print ch1
                    ch1 = getc(f1); // assign the next char to ch1
                }
                if(ch1=='\n')
                {
                    if(state2==0)
                    putchar('\n'); //when ch1 gets line end, print a new line
                    ch1 = getc(f1); //skip the '\n' and assign the next char to ch1
                }
                else if(state1==1) // if ch1 is EOF for the first time
                {
                    putchar('\n');
                    state1=0; //change f1 state to 0, so no more printing '\n'
                }
        
            while(ch2 !='\n' && ch2!=EOF)
            {
                putchar(ch2);
                ch2 = getc(f2);
            }
            if(ch2=='\n')
            {
                putchar('\n');
                ch2 = getc(f2);
            }
            else if(state2==1)
            {
                putchar('\n');
                state2=0;
            }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
