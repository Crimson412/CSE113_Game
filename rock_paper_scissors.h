#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  char name[100];
  int score;
  int loc;
  char icon;
  int laps;
}player;

void RPS(player, player);
