#include <stdio.h>
#define CM_TO_FEET 30.48
#define CM_TO_INCHES 0.3937

int main(void)
{
    float centimeters,left;
    int feet;
    printf("Enter the Centimeters: ");
    scanf("%f",&centimeters);
    while (centimeters>0) {
        feet = centimeters/CM_TO_FEET;
        left = (centimeters-feet*CM_TO_FEET)*CM_TO_INCHES;
        printf("%.1f cm = %d feet, %.1f inches\n",centimeters,feet,left);
        printf("Enter a height in centimeters (<=0 to qui): ");
        scanf("%f", &centimeters);
    }
    return 0;
}