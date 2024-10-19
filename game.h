#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"struct.h"

unsigned const int start_score = 10;
unsigned const int num_games = 3;


int manage_round(player[], int, char[], int, int, int);
int check_shared_loc(int, int, player[]);

void RPS(player*, player*);
void TicTacToe(player*, player*);
void num_guess(player*, player*);
