#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "tic_tac_toe.c"
#include "rock_paper_scissors.c"

typedef struct{
  char name[100];
  int score;
  int loc;
  char icon;
}player;

unsigned const int start_score = 100;

void printStage(player[], char[], int);
int check_shared_loc(int, int, player[]);

int main(){
  srand(time(NULL));
  char track [36];
  for(int i = 0; i < 36; i++){
    if(random()%3+1 == 1)
      track[i] = ' ';
    else if(random()%3+1 == 2)
      track[i] = '!';
    else
      track[i] = '*';
  }
  //char track[40] = {'-', '-', '*', '-', '-', '-', '*', '-', '-', '*', '-', '*', '-', '-', '*', '-', '-', '*', '-', '-', '*', '-', '-', '*', '-', '*', '-', '-', '*', '-','-', '-', '*', '-', '-', '-', '*', '-', '-', '*'}
  int player_count;
  printf("Welcome to Game in a Game (GIG)!!\nHow many players are there?\n");
  scanf("%d", &player_count);
  player players[player_count];
  for(int i = 0; i < player_count; i++){
    printf("Enter the name for player %d\n", i+1);
    scanf("%s", players[i].name);
    players[i].score = start_score;
    players[i].loc = 0;
    int check;
    do{
      check = 0;
      printf("Enter a unique character to represent player %d\n", i+1);
      scanf(" %c", &players[i].icon);
      for(int j = 0; j < player_count; j++)
	if(j != i)
	  if(players[j].icon == players[i].icon)
	    check++;
    }while(check);
  }
  printStage(players, track, player_count);
  //TicTacToe();
  //RPS();
}

void printStage(player players[], char track[], int player_count){
  char pos[36];

  for(int i = 0; i < 36; i++) pos[i] = ' ';
  for(int i = 0; i < player_count; i++){
    if(check_shared_loc(i, player_count, players))
      pos[players[i].loc] = players[i].icon;
    else
      pos[players[i].loc] = '^';
  }
  
  printf("\n\n\n\t\t\t      %c       %c       %c       %c       %c       %c       %c       %c       %c       %c\n", pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]);
  printf("\t\t\t  ---------------------------------------------------------------------------------\n");
  printf("\t\t\t  |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t  |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", track[0], track[1], track[2], track[3], track[4], track[5], track[6], track[7], track[8], track [9]);
  printf("\t\t\t  |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t  ---------------------------------------------------------------------------------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                                                               |   %c   | %c\n", pos[35], track[35], track[10], pos[10]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                                                               |   %c   | %c\n", pos[34], track[34], track[11], pos[11]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                             GAME                              |   %c   | %c\n", pos[33], track[33], track[12], pos[12]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                             IN A                              |   %c   | %c\n", pos[32], track[32], track[13], pos[13]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                             GAME!                             |   %c   | %c\n", pos[31], track[31], track[14], pos[14]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                                                               |   %c   | %c\n", pos[30], track[30], track[15], pos[15]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                                                               |   %c   | %c\n", pos[29], track[29], track[16], pos[16]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------                                                               ---------\n");
  printf("\t\t\t  |       |                                                               |       |\n"); 
  printf("\t\t\t%c |   %c   |                                                               |   %c   | %c\n", pos[28], track[28], track[17], pos[17]);
  printf("\t\t\t  |       |                                                               |       |\n");
  printf("\t\t\t  ---------------------------------------------------------------------------------\n");
  printf("\t\t\t  |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t  |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", track[27], track[26], track[25], track[24], track[23], track[22], track[21], track[20], track[19], track[18]);
  printf("\t\t\t  |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t  ---------------------------------------------------------------------------------\n");
  printf("\t\t\t      %c       %c       %c       %c       %c       %c       %c       %c       %c       %c\n\n\n\n", pos[27], pos[26], pos[25], pos[24], pos[23], pos[22], pos[21], pos[20], pos[19], pos[18]);
}

int check_shared_loc(int index, int count, player players[]){
  for(int i = 0; i < count; i++)
    if(i != index)
      if(players[i].loc == players[index].loc)
	return 0;
  return 1;
}
