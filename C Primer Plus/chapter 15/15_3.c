#include<stdio.h>
#include<stdbool.h>
#define SOLID 0
#define DOTTED 1
#define DASHED 2
#define BLUE 4
#define GREEN 2
#define RED 1
#define BLACK (RED&GREEN&GREEN)
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

const char *colors[8]={"black","red","green","yellow","blue","magenta","cyan","white"};
struct box_pros{
    bool opaque:1;
    unsigned int fill_color:3;
    unsigned int: 4;
    bool show_border:1;
    unsigned int border_color:3;
    unsigned int border_style: 2;
    unsigned int :2;
};

void show_settings(const struct box_pros *pb);

int main(void)
{
    struct box_pros box ={
        true, YELLOW,true, GREEN,DASHED
    };
    printf("The original box settings:\n");
    show_settings(&box);
    box.opaque = false;
    box.fill_color=WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("The modified box:\n");
    show_settings(&box);
    return 0;
}

void show_settings(const struct box_pros *pb)
{
    printf("The box is %s\n", pb->opaque==true?"opaque":"transparent");
    printf("The fill color is %s.\n",colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border==true?"Shown":"not shown");
    printf("The border colir is %s.\n", colors[pb->border_color]);
    printf("The border style is:");
    switch (pb->border_style)
    {
    case SOLID:
        printf("SOLID.\n");
        break;
    case DOTTED:
        printf("DOTTED.\n");
        break;
    case DASHED:
        printf("DASHED.\n");
        break;
    default:
        printf("Unknown type.\n");
    }
}