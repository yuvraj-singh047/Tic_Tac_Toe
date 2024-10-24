#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
int checkWinner(char *spaces, char player, char computer);
int checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char user_mark,player,computer;
    printf("***********TIC TAC TOE**********\n");
    drawBoard(spaces);
    printf("Choose your Marker (X/O): ");
    scanf("%c",&user_mark);
    player = user_mark;
    if (user_mark=='X') {
    computer = 'O';
    }
    else {
        computer='X';
    }
    int running = 1;

    drawBoard(spaces);

    while(running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = 0;
            break;
        } else if(checkTie(spaces)) {
            running = 0;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = 0;
            break;
        } else if(checkTie(spaces)) {
            running = 0;
            break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}

void drawBoard(char *spaces) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[0], spaces[1], spaces[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[3], spaces[4], spaces[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", spaces[6], spaces[7], spaces[8]);
    printf("     |     |     \n");
    printf("\n");
}

void playerMove(char *spaces, char player) {
    int number;
    do {
        printf("Enter a spot to place a marker (1-9): ");
        scanf("%d", &number);
        number--; // Convert user input to index
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (number < 0 || number > 8);
}

void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (1) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

int checkWinner(char *spaces, char player, char computer) {
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
        spaces[3] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
        spaces[6] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
        spaces[0] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
        spaces[1] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
        spaces[2] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
        spaces[0] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
        spaces[2] == player ? printf("YOU WIN!\n") : printf("YOU LOSE!\n");
    } else {
        return 0; // No winner
    }

    return 1; // Winner found
}

int checkTie(char *spaces) {
    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return 0; // No tie, spaces left
        }
    }
    printf("It's a tie!\n");
    return 1; // Tie
}
