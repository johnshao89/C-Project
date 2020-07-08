#include <stdio.h>

void to_base_n(int base, int num);

int main(void)
{
    int base, num;
    printf("Enter an integer and decimal: ");
    while((scanf("%d %d",&base, &num))==2)
        {
            to_base_n(base, num);
        }
    printf("Done");
    return 0;
}

void to_base_n(int base, int num)
{
    int digit;
    digit = base%num;
    printf("digit is %d\n",digit);
    if (base>= num)                 // if base <num, then base/num = 0
    to_base_n(base/num,num);        // base/num will be assigned to base in the next recursion
    printf("%d",digit);

}