#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
int random(int low,int up)
{
    srand(time(0));
    int num=(rand()%(up-low+1))+low;
    return num;
}
int i=0;
ll scores[100];
int main(){
    char choice;
    do{
        ll runs=0;
        int f1=0,f2=0;
        int flag=1;
        printf("\n******WELCOME TO THE GAME OF HAND CRICKET(BATTING EDITION)!!*******");
        printf("\nYOU HAVE TO ENTER A VALUE FROM 1 TO 6 EVERYTIME TILL YOU ARE OUT AND GAME ENDS!!");
        while(flag==1)
        {
            int computer_output=random(1,6);
            int user_input;
            printf("\n\nYOUR INPUT: ");
            scanf("%d",&user_input);
            if (user_input>6 || user_input<1){
                    printf("\nENTER VALUE ONLY FROM 1 TO 6");
                    continue;
            }
            else if(user_input==computer_output){
                printf("\nYOU ARE OUT");
                printf("\nCOMPUTER PLAYED THE NUMBER: %d",computer_output);
                printf("\nRUNS SCORED: %lld",runs);
                flag=0;
            }
            else{
                runs+=user_input;

                if(user_input==6){printf("\nYOU HIT A SIX!!");}
                if(user_input==4){printf("\nYOU HIT A FOUR!!");}

                if(f1==0){
                if(runs>=50 && runs<100)
                    {printf("\nYOU SCORED A FIFTY!");
                     f1=1;
                    }
                }

                if(f2==0){
                if(runs>=100)
                    {printf("\nYOU SCORED A HUNDRED!");
                     f2=1;
                    }
                }

                printf("\nCOMPUTER PLAYED THE NUMBER: %d",computer_output);
                printf("\nRUNS: %lld\n",runs);
            }
        }
        scores[i++]=runs;
        printf("\n\nDO YOU WANT TO PLAY AGAIN? PRESS 'y' OR 'Y' KEY TO CONTINUE OR ANY OTHER KEY TO QUIT. : ");
        scanf("\n");
        scanf("%c",&choice);
    }while(choice=='y' || choice=='Y');
    printf("\n\nSCORES SUMMARY: \n");
    for(int j=0;j<i;j++){printf("Score %d | %lld\n",j+1,scores[j]);}
    return 0;
}
