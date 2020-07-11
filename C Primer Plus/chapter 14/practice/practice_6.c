#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define LEN 40
struct player{
    unsigned int id;
    char first[LEN];
    char last[LEN];
    unsigned int plays;
    unsigned int hit;
    unsigned int walks;
    unsigned int RBI;
};
struct player team[20];
char *s_gets(char *st, int n);
int main(void)
{
    FILE *fp;
    int n,j=0;
    char filename[LEN];
    struct player *pst = (struct player*)malloc(sizeof(struct player));
    bool play_exist = false;
    int tot_play=0, tot_hit=0, tot_walks=0, tot_RBI=0;
    printf("Enter how many information you want to store:\n");
    scanf("%d", &n);
    while(getchar()!='\n')
    continue;
    printf("Enter the file location:\n");
    s_gets(filename, LEN);
    if (fp = fopen(filename, "r")==NULL)
    {
        printf("Can not open file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    while(fread(pst,sizeof(struct player),1,fp)==1)
    {
        for (int i=0; i<20; i++) //loop through the exisitng array, if the player exists, then add the parameters
        {
            if(team[i].id == pst->id)
            {
                play_exist = true;
                team[i].plays += pst->plays;
                team[i].hit += pst->hit;
                team[i].walks +=pst->walks;
                team[i].RBI += pst->RBI;
                break;
            }
        }
        if(play_exist == false) // after looping through the existing array and did not find the player, create the player
            {

                team[j].id = pst->id;
                strcpy(team[j].first, pst->first);
                strcpy(team[j].last, pst->last);
                team[j].plays = pst->plays;
                team[j].hit = pst->hit;
                team[j].walks =pst->walks;
                team[j].RBI = pst->RBI;
                j++;
            }
        play_exist = false;            
    }
    for(int k=0; k<20;k++)
    {
        printf("%d %s %s %d %d %d %d.\n", team[k].id,team[k].first,team[k].last, team[k].plays, team[k].hit,team[k].walks,team[k].RBI);
        tot_play+=team[k].plays;
        tot_hit+=team[k].hit;
        tot_walks+=team[k].walks;
        tot_RBI += team[k].RBI;
    }
    printf("The statistics for the team is :");
    printf("%d %d %d %d %f.\n", tot_play,tot_hit,tot_walks,tot_RBI,(float)tot_hit/tot_play);
    return 0;
    
}
