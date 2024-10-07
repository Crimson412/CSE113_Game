#include <stdio.h>

char emptyspace = '-';
char winner = 'N';
char position[3][3];

void TicTacToe(){
    int ui;
    position[0][0] = '-';
    position[1][0] = '-';
    position[2][0] = '-';
    position[0][1] = '-';
    position[1][1] = '-';
    position[2][1] = '-';
    position[0][2] = '-';
    position[1][2] = '-';
    position[2][2] = '-';
    printf("Welcome to Tic Tac Toe\nThe player that landed on the square goes first");
    printposition(position);
    printf("input 1 if you would like instructions on how to play the Tic Tac Toe mini game else input any other intager");
    scanf("%d",&ui);
    if (ui)
    {
        printf("for top left input 1:\nfor top middle input 2:\nfor top right input 3:\nfor middle left input 4:\nfor middle middle input 5:\n for middle right input 6:\n for bottom left input 7:\nfor bottom middle input 8:\nfor bottom right input 8:\nenjoy the game!!!");
    }
    while (winner == 'N'){
    
    printf("attacking player turn");
    scanf("%d",ui);
    if (ui == 1 && position[0][2] == emptyspace){
                    position[0][2] = 'X';
                } else if (ui == 2 && position[1][2] == emptyspace) {
                    position[1][2] = 'X';
                } else if (ui == 3 && position[2][2] == emptyspace) {
                    position[2][2] = 'X';
                } else if (ui == 4 && position[0][1] == emptyspace) {
                    position[0][1] = 'X';
                } else if (ui == 5 && position[1][1] == emptyspace) {
                    position[1][1] = 'X';
                } else if (ui == 6 && position[2][1] == emptyspace) {
                    position[2][1] = 'X';
                } else if (ui == 7 && position[0][0] == emptyspace) {
                    position[0][0] = 'X';
                } else if (ui == 8 && position[1][0] == emptyspace) {
                    position[1][0] = 'X';
                } else if (ui == 9 && position[2][0] == emptyspace) {
                    position[2][0] = 'X';
                } else {
                    printf("Lost your turn");
                }
    winner = checkwin(position);            
    printposition(position);

    printf("defending player turn");
    scanf("%d",ui);
    if (ui == 1 && position[0][2] == emptyspace){
                    position[0][2] = 'O';
                } else if (ui == 2 && position[1][2] == emptyspace) {
                    position[1][2] = 'O';
                } else if (ui == 3 && position[2][2] == emptyspace) {
                    position[2][2] = 'O';
                } else if (ui == 4 && position[0][1] == emptyspace) {
                    position[0][1] = 'O';
                } else if (ui == 5 && position[1][1] == emptyspace) {
                    position[1][1] = 'O';
                } else if (ui == 6 && position[2][1] == emptyspace) {
                    position[2][1] = 'O';
                } else if (ui == 7 && position[0][0] == emptyspace) {
                    position[0][0] = 'O';
                } else if (ui == 8 && position[1][0] == emptyspace) {
                    position[1][0] = 'O';
                } else if (ui == 9 && position[2][0] == emptyspace) {
                    position[2][0] = 'O';
                } else {
                    printf("Lost your turn");
                }
                winner = checkwin(position);
                printposition(position);
    }


}

void printposition(char position[3][3]){
    printf("-------|------|------");
    printf("   %c  |  %c  |  %c ",position[0][0],position[1][0],position[2][0]);
    printf("-------|------|------");
    printf("   %c  |  %c  |  %c ",position[3][1],position[4][1],position[5][1]);
    printf("-------|------|------");
    printf("   %c  |  %c  |  %c ",position[6][2],position[7][2],position[8][2]);
    printf("-------|------|------");
}

char checkwin(char position[3][3]){
    for (int i = 0; i < 3; i++)
    {
        if (position[0][i] == position[1][i] && position[0][i] == position[2][i] && position[i][0] != emptyspace)
        {
            char winner = position[0][i];
            printf("the winner is %c",winner);
            return winner;
        }
        if (position[i][0] == position[i][1] && position[i][0] == position[i][2] && position[i][0] != emptyspace){
            char winner = position[i][0];
            printf("the winner is %c",winner);
            return winner;
        }
    }
    if (position[0][0] == position[1][1] && position[0][0] == position[2][2] && position[0][0] != emptyspace){
        char winner;
        winner = position[0][0];
        printf("the winner is %c",winner);
        return winner;
    }
    if (position[2][0] == position[1][1] && position[2][0] == position[0][2] && position[2][0] != emptyspace){
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
            if (position[i][j] == '-')
                draw = 0;
            
        }
        
    }
    if (draw){
        printf("you both lose");
        return 'D';
    } else return 'N';

}

int main(){
  TicTacToe();
}
