#include"rock_paper_scissors.h"

void RPS(player* p1, player* p2){
    int ui;
    printf("Welcome to Rock Paper Scissors\nPress 1 if you would like a tutorial else press another number\n");
    scanf("%d",&ui);
    if (ui)
    {
      printf("Player %s will go first and will choose what they want to play r,p,s while Player %s closes their eyes\nPlay will continue until someone wins, good luck!\n", p1->name, p2->name);
    }
    char p1move,p2move;
    while(1){
      printf("Player %s goes now and Player %s close your eyes\n", p1->name, p2->name);
      scanf(" %c",&p1move);
      system("clear");
    
      printf("Player %s goes now and Player %s close your eyes\n", p2->name, p1->name);
      scanf(" %c",&p2move);
      p1move = tolower(p1move);
      p2move = tolower(p2move);

      switch (p1move)
	{
	case 'r':
	  switch (p2move)
	    {
	    case 'p':
	      printf("Player %s chose rock Player %s chose paper\nPlayer %s wins!\n", p1->name, p2->name, p2->name);
	      p2->score += RPSprize;
	      p1->score -= RPSloss;
	      return;

	    case 's':
	      printf("Player %s chose rock Player %s chose scissors\nPlayer %s wins\n",  p1->name, p2->name, p1->name);
	      p1->score += RPSprize;
	      p2->score -= RPSloss;
	      return;
	    }
	  break;

	case 'p':
	  switch (p2move)
	    {
	    case 'r':
	      printf("Player %s chose paper Player %s chose rock\nPlayer %s wins!\n", p1->name, p2->name, p1->name);
	      p1->score += RPSprize;
	      p2->score -= RPSloss;
	      return;
	    case 's':
	      printf("Player %s chose paper Player %s chose scissors\nPlayer %s wins!\n", p1->name, p2->name, p2->name);
	      p2->score += RPSprize;
	      p1->score -= RPSloss;
	      return;
	    }
	  break;


	case 's':
	  switch (p2move)
	    {
	    case 'r':
	      printf("Player %s chose scissors Player %s chose rock\nPlayer %s wins!\n", p1->name, p2->name, p2->name);
	      p2->score += RPSprize;
	      p1->score -= RPSloss;
	      return;
        
	    case 'p':
	      printf("Player %s chose scissors Player %s chose paper\nPlayer %s wins!\n", p1->name, p2->name, p1->name);
	      p1->score += RPSprize;
	      p2->score -= RPSloss;
	      return;
	    }
	  break;    
	}
      printf("A tie! Get ready for the next round!\n");  
    }
}
