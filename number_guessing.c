#include"number_guessing.h"

void num_guess(player* p1, player* p2){
  srand(time(NULL));
  int value = random()%101;;
  int guess1 = -1;
  int guess2 = -1;
  printf("Welcome to guess the number!\nPlayers will take turn guessing a secret number between 0 and 100.\nFreedback will be provided after each guess.\nThe player who guesses the number correctly wins!\nGood Luck!\n\n");
  while(1){
    printf("Player %s enter your guess: ", p1->name);
    scanf("%d", &guess1);
    if(guess1 == value){
      p1->score += NGprize;
      p2->score -= NGloss;
      printf("Player %s you guessed Correctly, You gained %d to your score.\nPlayer %s you lost %d to your score!\n\n", p1->name, NGprize, p2->name, NGloss);
      return;
    }
    else if (guess1 < value)
      printf("Your guess was too low!\n");
    else
      printf("Your guess was too high!\n");

    printf("Player %s enter your guess: ", p2->name);
    scanf("%d", &guess2);
    if(guess2 == value){
      p2->score += NGprize;
      p1->score -= NGloss;
      printf("Player %s you guessed Correctly, You gained %d to your score.\nPlayer %s you lost %d to your score!\n\n", p2->name, NGprize, p1->name, NGloss);
      return;
    }
    else if (guess2 < value)
      printf("Your guess was too low!\n");
    else
      printf("Your guess was too high!\n");
  }
}
