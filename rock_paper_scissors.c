#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void RPS(){
    int ui;
    printf("Welcome to Rock Paper Scissors\nPress 1 if you would like a tutorial else press another number\n");
    scanf("%d",&ui);
    if (ui)
    {
        printf("the player who landed on the tile will go first will choose what they want to play r,p,s while the chalanged player closes there eyes\n");
    }
    char p1move,p2move;
    printf("player 1 goes now and second player close your eyes\n");
    scanf(" %c",&p1move);
    system("clear");
    
    printf("player 2 goes now and first player close your eyes\n");
    scanf(" %c",&p2move);
    p1move = tolower(p1move);
    p2move = tolower(p2move);

    switch (p1move)
    {
    case 'r':
        switch (p2move)
        {
        case 'r':
            printf("player 1 chose rock player 2 chose rock\nyou both lose\n");
            break;
        
        case 'p':
            printf("player 1 chose rock player 2 chose paper\nplayer two wins\n");
            break;

        case 's':
            printf("player 1 chose rock player 2 chose scissors\nplayer 1 wins\n");
            break;
        }
        break;

        case 'p':
        switch (p2move)
        {
        case 'r':
            printf("player 1 chose paper player 2 chose rock\nplayer 1 wins\n");
            break;
        
        case 'p':
            printf("player 1 chose paper player 2 chose paper\nyou both lose\n");
            break;

        case 's':
            printf("player 1 chose paper player 2 chose scissors\nplayer 2 wins\n");
            break;
        }
        break;


        case 's':
        switch (p2move)
        {
        case 'r':
            printf("player 1 chose scissors player 2 chose rock\nplayer 2 wins\n");
            break;
        
        case 'p':
            printf("player 1 chose scissors player 2 chose paper\nplayer 1 wins\n");
            break;

        case 's':
            printf("player 1 chose scissors player 2 chose scissors\nyou both lose\n");
            break;
        }
        break;    
    }
}