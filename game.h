#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
  char name[100];
  int score;
  int loc;
  char icon;
  int laps;
}player;

unsigned const int start_score = 10;
unsigned const int num_games = 2;

int manage_round(player[], int, char[], int, int, int);
int check_shared_loc(int, int, player[]);

void RPS(player, player);
void TicTacToe(player, player);
