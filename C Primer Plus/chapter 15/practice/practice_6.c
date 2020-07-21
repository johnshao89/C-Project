#include<stdio.h>

typedef struct font{
    unsigned int font_id:8;
    unsigned int font_size:7;
    unsigned int:1;
    unsigned int font_align: 2;
    unsigned int bold:1;
    unsigned int italic:1;
    unsigned int undersocre:1; 
}Font;
const char *on_off[2]={"off","on"};
const char *alig[3]={"left","center","right"};
#define off 0
#define on 1
#define left 0
#define center 1
#define right 2
void show_menu(Font*);
char getletter(char *);
void eatline(void);
int main(void)
{
    char choice;
    int id, size,alignment;;
    Font font={1,12,left,off,off,off};
    show_menu(&font);
    while((choice = getletter("fsabiuq")) && choice !='q')
    {
        switch (choice)
        {
        case 'f':
        printf("Enter font ID:0 to 255:\n");
        scanf("%d", &id);
        font.font_id=id;
        eatline();
            break;
        case 's':
        printf("Enter the size: 0 to 127\n");
        scanf("%d", &size);
        font.font_size=size;
        eatline();
            break;
        case 'a':
        printf("select alignment:\n");
        puts("l)left    c)center    r)right");
        choice = getletter("lcr");
        /*to be continued


        */ 
        default:
            break;
        }
        show_menu(&font);

    }
    puts("Bye");
    return 0;
}

void show_menu(Font *font)
{
    puts("ID SIZE ALIGNMENT    B    I    U");
    printf("%d%-5d%-10s%19s%23s%27s\n", font->font_id, font->font_size, alig[font->font_align], on_off[font->bold],on_off[font->italic], on_off[font->undersocre]);
    puts("f)change font     s)change size       a)change alignment");
    puts("b)toggle bold     i)toggle italic     u)toggle underline");
    puts("q)quit");
}

char getletter(char *string)
{
    char ret_val;

    while((ret_val =getchar()) && strchr(ret_val,string)==NULL)
    {
        eatline();
        printf("please only enter %s.\n", string);
    }
    eatline();
    return ret_val;
}
void eatline(void)
{
    while(getchar()!='\n')
    continue;
}