#include"tic_tac_toe.h"

void TicTacToe(player* p1, player* p2){
    int ui;
    char pos[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    printf("Welcome to Tic Tac Toe\nThe player that landed on the square goes first");
    print_pos(pos);
    printf("input 1 if you would like instructions on how to play the Tic Tac Toe mini game else input any other integer: ");
    scanf("%d", &ui);
    if (ui == 1)
        printf("For top left input: 1\nFor top middle input: 2\nFor top right input: 3\nFor middle left input: 4\nFor middle middle input: 5\nFor middle right input: 6\nFor bottom left input: 7\nFor bottom middle input: 8\nFor bottom right input: 9\nEnjoy the game!!!\n");
    while (1){    
      printf("Player %s (X) turn: ", p1->name);
      scanf(" %d", &ui);
      if (ui == 1 && pos[0][0] == '1')
	pos[0][0] = 'X';
      else if (ui == 2 && pos[0][1] == '2')
	pos[0][1] = 'X';
      else if (ui == 3 && pos[0][2] == '3') 
        pos[0][2] = 'X';
      else if (ui == 4 && pos[1][0] == '4')
        pos[1][0] = 'X';
      else if (ui == 5 && pos[1][1] == '5') 
        pos[1][1] = 'X';
      else if (ui == 6 && pos[1][2] == '6')
        pos[1][2] = 'X';
      else if (ui == 7 && pos[2][0] == '7')
        pos[2][0] = 'X';
      else if (ui == 8 && pos[2][1] == '8')
        pos[2][1] = 'X';
      else if (ui == 9 && pos[2][2] == '9')
        pos[2][2] = 'X';
      else
        printf("Lost your turn!\n");
    winner = checkwin(pos);
    print_pos(pos);
    if(winner == 'X'){
      p1->score += TTTprize;
      p2->score -= TTTloss;
      return;
    }
    else if(winner == 'D'){
      p1->score -= TTTloss;
      p2->score -= TTTloss;
      return;
    }
    ui = 1;
    
    printf("Player %s (O) turn: ", p2->name);
    scanf(" %d", &ui);
    if (ui == 1 && pos[0][0] == '1')
      pos[0][0] = 'O';
    else if (ui == 2 && pos[0][1] == '2')
      pos[0][1] = 'O';
    else if (ui == 3 && pos[0][2] == '3') 
      pos[0][2] = 'O';
    else if (ui == 4 && pos[1][0] == '4')
      pos[1][0] = 'O';
    else if (ui == 5 && pos[1][1] == '5') 
      pos[1][1] = 'O';
    else if (ui == 6 && pos[1][2] == '6')
      pos[1][2] = 'O';
    else if (ui == 7 && pos[2][0] == '7')
      pos[2][0] = 'O';
    else if (ui == 8 && pos[2][1] == '8')
      pos[2][1] = 'O';
    else if (ui == 9 && pos[2][2] == '9')
      pos[2][2] = 'O';
    else
      printf("Lost your turn!\n");
    winner = checkwin(pos);
    print_pos(pos);
    if(winner == 'O'){
      p2->score += TTTprize;
      p1->score -= TTTloss;
      return;
    }
    }
}

void print_pos(char position[3][3]){
    printf("\n-------|-------|-------");
    printf("\n   %c   |   %c   |   %c ",position[0][0],position[0][1],position[0][2]);
    printf("\n-------|-------|-------");
    printf("\n   %c   |   %c   |   %c ",position[1][0],position[1][1],position[1][2]);
    printf("\n-------|-------|-------");
    printf("\n   %c   |   %c   |   %c ",position[2][0],position[2][1],position[2][2]);
    printf("\n-------|-------|-------\n");
}

char checkwin(char position[3][3]){
    for (int i = 0; i < 3; i++)
    {
        if (position[0][i] == position[1][i] && position[0][i] == position[2][i] &&  (position[0][i] == 'X' || position[0][i] == 'O'))
        {
            char winner = position[0][i];
            printf("the winner is %c",winner);
            return winner;
        }
        if (position[i][0] == position[i][1] && position[i][0] == position[i][2] &&  (position[i][0] == 'X' || position[i][0] == 'O')){
            char winner = position[i][0];
            printf("the winner is %c",winner);
            return winner;
        }
    }
    if (position[0][0] == position[1][1] && position[0][0] == position[2][2] && (position[0][0] == 'X' || position[0][0] == 'O')){
        char winner;
        winner = position[0][0];
        printf("the winner is %c",winner);
        return winner;
    }
    if (position[2][0] == position[1][1] && position[2][0] == position[0][2] &&  (position[2][0] == 'X' || position[2][0] == 'O')){
        char winner;
        winner = position[0][0];
        printf("the winner is %c",winner);
        return winner;
    }

    int draw = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (position[i][j] != 'X' && position[i][j] != 'O')
                draw = 0;
            
        }
        
    }
    if (draw){
        printf("you both lose");
        return 'D';
    } else return 'N';

}
