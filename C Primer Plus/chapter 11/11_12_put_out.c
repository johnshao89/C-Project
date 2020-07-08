#include <stdio.h>

#define DEF "I am a #defined string."

int main(void)
{
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";
    puts("I'm an argument to puts()."); //puts will add an newline at the end of string
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]); //start from str1[5] to the end of the string
    puts(str2+4);
    return 0;
}