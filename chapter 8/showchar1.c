#include <stdio.h>

void display(char cr, int lines, int width);
int main(void)
{
    int ch, rows, cols;
    printf("Enter a character and two integers:\n");
    while ((ch=getchar())!='\n')
    {
        if(scanf("%d %d",&rows, &cols)!=2)
        break;
        display(ch,rows,cols);
        while (getchar()!='\n')
        continue;
        printf("Enter next set character and two integers:\n");
        printf("Enter a new line to quit.\n");
    }
    printf("Done\n");
    return 0;


}
void display(char cr, int lines, int width)
{
    int i, k;
    for (i=0;i<lines;i++)
        {
            for (k=0;k<width;k++)
            putchar(cr);
            putchar('\n');
        }
}