#include <stdio.h>

#define SLEN 40
#define LIM 5

int main(void)
{
    const char *mytalents[LIM] = {                  //pointer has a size of 4 byte in 32bit machine
        "Adding　numbers　swiftly",
"Multiplying　accurately","Stashing　data",
"Following　instructions　to　the　letter",
"Understanding　the　C　language"};
    char yourtalents[LIM][SLEN] = {
        "Walking　in　a　straight　line",
"Sleeping","Watching　television",
"Mailing　letters","Reading　email"
    };
    int i;
    puts("Let's compare talents.");
    printf("%-36s   %-25s\n","My Talents","Your Talents");
    printf("\nsize of mytalents: %zd, size of your talents: %zd\n", sizeof(mytalents),sizeof(yourtalents));

}