#include <stdio.h>
void one_three(void);
void two(void);
int main(void)
{
    printf("Starting now:\n");
    one_three();
    printf("Done!\n");
}
void one_three(void)
{
    printf("One\n");
    two();
    printf("three\n");
}
void two(void)
{
    printf("two\n");
}