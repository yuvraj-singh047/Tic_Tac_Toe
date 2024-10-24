**Tic-Tac-Toe Game**

This is a simple Tic-Tac-Toe game implemented in C. The game allows you to play against the computer in a 3x3 grid, taking turns to place your marker. The objective is to get three of your markers in a row, column, or diagonal to win the game. The computer moves randomly.
Features

  Play as either 'X' or 'O'.
  Turn-based gameplay against the computer.
  Detects a winner or a tie.
  Simple and easy-to-understand console interface.

**How to Play**

    Clone the repository or copy the source code.
    Compile the code using a C compiler like gcc.


```gcc -o tic_tac_toe tic_tac_toe.c```

Run the executable:


```./tic_tac_toe```

You will be prompted to choose your marker ('X' or 'O').
Enter a number (1-9) corresponding to the position on the board to place your marker:


      1 | 2 | 3
     -----------
      4 | 5 | 6
     -----------
      7 | 8 | 9

    The game will alternate turns between you and the computer.
    The game ends when either you or the computer wins, or when there's a tie.

**Functions**

  drawBoard(char *spaces): Displays the current state of the Tic-Tac-Toe board.
  
  playerMove(char *spaces, char player): Handles the player's move by placing their marker on the board.
  
  computerMove(char *spaces, char computer): Randomly selects an available spot for the computer's move.
  
  checkWinner(char *spaces, char player, char computer): Checks if there is a winner after each turn.
  
  checkTie(char *spaces): Checks if the game is a tie (i.e., no more available moves).

**Example Game Flow**



***********TIC TAC TOE**********
Choose your Marker (X/O): X
Enter a spot to place a marker (1-9): 5

```     
     |     |     
_____|_____|_____
     |     |     
     |  X  |     
_____|_____|_____
     |     |     
     |     |
```

Computer placed 'O'.

Requirements

    A C compiler such as GCC.

License

This project is open-source and available under the MIT License.
