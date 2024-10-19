#include<stdio.h>
#include"struct.h"

char winner = 'N';

void print_pos(char[][3]);
char checkwin(char[][3]);
void TicTacToe(player*, player*);


unsigned const int TTTprize = 100;
unsigned const int TTTloss = 50;

