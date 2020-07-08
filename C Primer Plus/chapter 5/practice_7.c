#include <stdio.h>

int main(void)
{
    int first_num, second_num, left;
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d",&second_num);
    printf("Now enter the first operand: ");
    scanf("%d", &first_num);
    while (first_num > 0) {
        left = first_num%second_num;
        printf("%d %% %d is %d\n", first_num,second_num,left);
        printf("Now enter the first operand: ");
        scanf("%d", &first_num);
    }
    return 0;
}