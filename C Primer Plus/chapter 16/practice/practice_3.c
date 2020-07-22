#include<stdio.h>
#include<math.h>
#define RAD_TO_DEG (180/(4*atan(1)))
typedef struct polar_v{
    float degree;
    float magnitude;
}Polar_V;

typedef struct reg_v{
    float x;
    float y;
}Reg_v;

Reg_v polar_to_reg(Polar_V *);

int main(void)
{
    Polar_V polar;
    Reg_v reg;
    printf("Enter the degree:\n");
    while(scanf("%f", &polar.degree)==1)
    {
        printf("Enter the magnitude:\n");
        scanf("%f", &polar.magnitude);
        reg = polar_to_reg(&polar);
        printf("After transformation, %.2f is X and %.2f is Y\n", reg.x, reg.y);
        printf("Enter the next degree:");
    }
    return 0;
}

Reg_v polar_to_reg(Polar_V *pst)
{
    Reg_v ret_val;
    ret_val.x = (pst->magnitude)*cosf(pst->degree/RAD_TO_DEG);
    ret_val.y = (pst->magnitude)*sinf(pst->degree/RAD_TO_DEG);
    return ret_val;
}