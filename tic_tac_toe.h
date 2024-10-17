#include<stdio.h>

char winner = 'N';

typedef struct{
  char name[100];
  int score;
  int loc;
  char icon;
  int laps;
}player;

void print_pos(char[][3]);
char checkwin(char[][3]);
void TicTacToe(player, player);
