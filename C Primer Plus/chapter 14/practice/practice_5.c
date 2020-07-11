#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define LEN 40
#define CSIZE 4
struct name{
    char first[LEN];
    char last[LEN];
};

struct student{
    struct name names;
    float grade[3];
    float average;
};
char *s_gets(char *st, int n);
int main(void)
{
    struct student students[CSIZE]={
       {{"Wenjie","Shao"}},
        {{"Yue", "Yin"}},
        {{"John", "Doe"}},
        {{"Smith", "Johns"}}
    };
    int count=0, index;
    char first[LEN];
    char last[LEN];
    bool found_student = false;
    float tot=0;
    printf("Enter the first name of the first student:\nPress Enter at the new line to stop\n");
    while(count<CSIZE && s_gets(first, 2*LEN)!=NULL && first[0]!='\0')
    {
        printf("Enter the student's last name:\n");
        s_gets(last,LEN);
        for (index=0; index <CSIZE; index++)
        if(strcmp(first, students[index].names.first)==0 && strcmp(last, students[index].names.last)==0)
        {
            found_student=true;
            break;
        }
        if(!found_student)
        {
            printf("Can not find the student. Re-enter the first name:\n");
            continue;
        }
        printf("Enter the student's three grades:");
        scanf("%f %f %f", &students[index].grade[0], &students[index].grade[1], &students[index].grade[2]);
        while(getchar()!='\n')
        continue;
        students[index].average = (students[index].grade[0] + students[index].grade[1] +students[index].grade[2])/3.0;
        count++;
        if(count<CSIZE)
        printf("Enter the next student's first name:\n");
    }
    for(index =0; index <count; index++)
    {
        printf("%s %s, three grades are %.1f, %.1f, %.1f, average is %.1f\n", students[index].names.first, students[index].names.last, students[index].grade[0],
        students[index].grade[1], students[index].grade[2], students[index].average);
        tot += students[index].average;
    }
    printf("The class average is %.1f.\n", tot/count);
    return 0;

}

char *s_gets(char *st, int n)
{
    char *ret_val, *find;
    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
        *find = '\0';
        else while(getchar()!='\n')
        continue;
    }
    return ret_val;
}