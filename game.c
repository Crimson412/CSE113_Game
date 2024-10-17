#include"game.h"

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
  int player_count;
  printf("Welcome to Game in a Game (GIG)!!\nHow many players are there?\n");
  scanf("%d", &player_count);
  if(player_count < 2)
    player_count = 2;
  player players[player_count];
  for(int i = 0; i < player_count; i++){
    printf("Enter the name for player %d\n", i+1);
    scanf("%s", players[i].name);
    players[i].score = start_score;
    players[i].loc = 0;
    players[i].laps = 1;
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
  printf("How many rounds would you like to play? (Max 10)\n");
  int rounds;
  scanf("%d", &rounds);
  if (rounds < 1 || rounds > 10)
    rounds = 10;
  printf("\nHere are the Rules: Each player will take turns in order. Rolling a 10 sided die. The square that you land on determines your turn.\n\" \" (empty space) indicates a safe square, and your score increases by (1-10) * the value you rolled\n\"!\" (exclamation mark) indicates a bad square. Your score will decrease by (1-10) * the value rolled.\n'*' (mini-game) this will prompt the player to go into a mini-game with another randomly selected player.\nThe winner gains 10*value rolled and the loser loses that amount. If there is a tie nothing happens.\nPlayers progress on the track will be showed by their icon above their respective squares. If more than one player occupies a square the \n\'^\' character will be displayed over that square.\nOnce the player in the lead has crossed the start location a number of times = to the amount of rounds, the game ends and that player gains \nan additional 10*value rolled points. Each player starts out with 10 points\nGood luck and enjoy Game in a Game!\n\n");
  int max_round = players[0].laps;
  for(;;){
    for(int j = 0; j < player_count; j++){
      printf("Player %d's turn! enter any character to roll %s! ", j+1, players[j].name);
      char c[256];
      scanf("%s", c);
      int roll =  random()%10+1;
      int result = manage_round(players, j, track, player_count, roll, max_round);
      if(result){
	int rand = random()%num_games+1;
	player p2 = players[j];
	while(p2.icon == players[j].icon)
	  p2 = players[random()%player_count];
	printf("%s and %s have been chosen for a random MINIGAME! enter any character to continue: ", players[j].name, p2.name);
	scanf("%s", c);
	switch(rand)
	{
	case 1: RPS(players[j], p2);
	  break;
        case 2: TicTacToe(players[j], p2);
	  break;
	default: printf("Minigame selection error!!\n");
	}
      }
      if(players[j].laps > max_round)
	max_round = players[j].laps;
      if(max_round > rounds){
	players[j].score += 10*roll;
	break;
      }
    }
  }
}

int manage_round(player players[], int p1, char track[], int player_count, int roll, int round){
  char pos[36];
  int ret = 0;
  int old_score = players[p1].score;
  if(players[p1].loc + roll > 35){
    players[p1].loc = players[p1].loc + roll - 36;
    players[p1].laps += 1;
  }
  else
    players[p1].loc += roll;
  if(track[players[p1].loc] == ' ')
    players[p1].score += (random()%10+1)*roll;
  else if (track[players[p1].loc] == '!')
    players[p1].score -= (random()%10+1)*roll;
  else
    ret = random()%num_games+1;
  for(int i = 0; i < 36; i++) pos[i] = ' ';
  for(int i = 0; i < player_count; i++){
    if(check_shared_loc(i, player_count, players))
      pos[players[i].loc] = players[i].icon;
    else
      pos[players[i].loc] = '^';
  }
  
  printf("\n\n\n\t\t\t         %c       %c       %c       %c       %c       %c       %c       %c       %c       %c\n", pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], pos[6], pos[7], pos[8], pos[9]);
  printf("\t\t\t     ---------------------------------------------------------------------------------\n");
  printf("\t\t\t     |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t     |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", track[0], track[1], track[2], track[3], track[4], track[5], track[6], track[7], track[8], track [9]);
  printf("\t\t\t     |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t     ---------------------------------------------------------------------------------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                                                               |   %c   | %c\n", pos[35], track[35], track[10], pos[10]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------                           Round: %d\t                     ---------\n", round);
  printf("     Value Rolled: %d\t     |       |                                                               |       |                ---Player %d---\n", roll, p1+1); 
  printf("\t\t\t   %c |   %c   |                                                               |   %c   | %c\n", pos[34], track[34], track[11], pos[11]);
  printf("\t\t\t     |       |                                                               |       |                ---Name: %s---\n", players[p1].name);
  printf("\t\t\t     ---------                                                               ---------                ---Icon: \'%c\'---\n", players[p1].icon);
  printf("\t\t\t     |       |                                                               |       |                ---Current Score: %d---\n", old_score); 
  printf("\t\t\t   %c |   %c   |                             GAME                              |   %c   | %c\n", pos[33], track[33], track[12], pos[12]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------                                                               ---------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                             IN A                              |   %c   | %c\n", pos[32], track[32], track[13], pos[13]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------                                                               ---------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                             GAME!                             |   %c   | %c\n", pos[31], track[31], track[14], pos[14]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------                                                               ---------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                                                               |   %c   | %c\n", pos[30], track[30], track[15], pos[15]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------                                                               ---------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                                                               |   %c   | %c\n", pos[29], track[29], track[16], pos[16]);
  printf("\t\t\t     |       |                         New Score: %d\t                     |       |\n", players[p1].score);
  printf("\t\t\t     ---------                                                               ---------\n");
  printf("\t\t\t     |       |                                                               |       |\n"); 
  printf("\t\t\t   %c |   %c   |                                                               |   %c   | %c\n", pos[28], track[28], track[17], pos[17]);
  printf("\t\t\t     |       |                                                               |       |\n");
  printf("\t\t\t     ---------------------------------------------------------------------------------\n");
  printf("\t\t\t     |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t     |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |\n", track[27], track[26], track[25], track[24], track[23], track[22], track[21], track[20], track[19], track[18]);
  printf("\t\t\t     |       |       |       |       |       |       |       |       |       |       |\n");
  printf("\t\t\t     ---------------------------------------------------------------------------------\n");
  printf("\t\t\t         %c       %c       %c       %c       %c       %c       %c       %c       %c       %c\n", pos[27], pos[26], pos[25], pos[24], pos[23], pos[22], pos[21], pos[20], pos[19], pos[18]);

  return ret;
}

int check_shared_loc(int index, int count, player players[]){
  for(int i = 0; i < count; i++)
    if(i != index)
      if(players[i].loc == players[index].loc)
	return 0;
  return 1;
}
