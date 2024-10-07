#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "tic_tac_toe.c"

typedef struct{
  char name[100];
  int score;
  int loc;
  char icon;
}player;

unsigned const int start_score;

void printStage(player[], char[], int);

int main(){
  srand(time(NULL));
  char track [38];
  for(int i = 0; i < 38; i++){
    if(random()%3+1 == 1)
      track[i] = ' ';
    else if(random()%3+1 == 2)
      track[i] = '!';
    else
      track[i] = '*';
    printf("%c", track[i]);
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
    players[i].score = 0;
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
  TicTacToe();
}

void printStage(player players[], char track[], int player_count){
  int check = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < player_count; j++){
      check = 0;
      if(players[j].loc == i){
	printf("   %c", track[i]);
	check++;
      }
    }
    if(check)
      printf("    ");
  }
}
