#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "win.h"
#include "board.h"

/*This file is used to tell if you win, and gives commands if you do

There are 4 ending game outcomes:

Horizontal win
Vertical win
Diagonal win
Tie

Horizontal: 
-Iterate through each char in each row
-If the char is any player, start an increment starting at 1
-Keep going for that character until you either meet your required increment or hit another character

Vertical:
-Same as Horizontal but incrementing the column

Diagonal;
2 types of diagonal wins:
/ win and \ win. 

for / win:
start increment at 1 when you get a player char
-char[i][j] --> i decreases, j increases for checking
Starting values loops:
-loop 1: char[i][j] --> i increases (until it reaches numRows), j stays at 1
then:
-loop 2: char[i][j] --> i stays at numRows, j starts at 1 until numCols
These are two loops within loops but with the same i and j functions

for \ win:
start increment at 1 when you get a player char
-char[i][j] --> i increases, j increases for checking
starting values loops:
-loop 1: char[i][j] --> i decreases from numRows until 0. j stays at 1
then:
-loop 2: char[i][j] --> i stays at 0, j starts at 1 until numCols

for tie:
Go through each blank character spot and check if they've been taken*/

/*
This function checks if there is win in the horizontal direction.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void HorizontalWin(char** board, int winNum, int numRows, int numCols) {
    int increment = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 1; j < numCols + 1; ++j) {
            if (board[i][j] == 'X' || board[i][j] == 'O' ) { //Makes sure it's a player char
                increment = 1;
                for (int k = 1; (k <= numCols + 1) ; ++k) {
                    if (board[i][k + j] == board[i][j]) { //Goes right on the column with each iteration of k
                        increment += 1; //The increment increases each time there is a player character in a row
                        if (increment >= winNum) { //The increment reaches winNum
                            if (board[i][j] == 'X') { //The board that was the first to be checked on in this loop
                                printf("Player 1 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                            else if (board[i][j] == 'O') { //Same for player 2 
                                printf("Player 2 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}


/*
This function check if there is a win in the vertical direction.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void VerticalWin(char** board, int winNum, int numRows, int numCols) {
    int increment = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 1; j < numCols + 1; ++j) {
            if (board[i][j] == 'X' || board[i][j] == 'O' ) { //Makes sure it's a player char
                increment = 1;
                for (int k = 1; (k <= i) ; ++k) {
                    if (board[i - k][j] == board[i][j]) {//Goes up on the rows with each iteration of k 
                        increment += 1; //The increment increases each time there is a player character in a row
                        if (increment >= winNum) { //The increment reaches winNum
                            if (board[i][j] == 'X') { //The board that was the first to be checked on in this loop
                                printf("Player 1 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                            else if (board[i][j] == 'O') { //Same for player 2
                                printf("Player 2 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}


/*
This function checks if all of the columns are taken up by an X or an O, it is a tie.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void Tie(char** board, int winNum, int numRows, int numCols) {
    int dimensions = numRows * numCols;
    int increment = 0;
    for (int i = 0; i < numRows; ++i) { //Since rows aren't slid by 1
        for (int j = 1; j < numCols + 1; ++j) { //Since columns are slid by 1
            if (board[i][j] != '*') { //Checking each space to make sure it isn't blank
                increment += 1; 
                if(increment == dimensions) { //This would mean the board is full
                printf("Tie game!\n");
                FreeBoard(board, numRows);
                exit(0);
                }
            }
        }

    }
}

/*
This function checks if there is a win from top right to bottom right diagonal in the board.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void Diagonal45Degrees(char** board, int winNum, int numRows, int numCols) {
    //This function checks for the 45 degree horizontal (/)
    int increment = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 1; j < numCols + 1; ++j) {
            if (board[i][j] == 'X' || board[i][j] == 'O' ) { //Checks if a player has played
                increment = 1; //Begins the increment
                for (int k = 1; (i >= k) && (j + k <= numCols + 1) ; ++k) { //This is too make sure the checking doesn't go outside of the arrays (must stay within the columns and rows)
                    if (board[i - k][j + k] == board[i][j]) { //checks diagonally 
                        increment += 1; //Increment the ticker
                        if (increment >= winNum) { //If the ticker is the same or more as the winning number
                            if (board[i][j] == 'X') { //This checks the first character of the iteration you were going through
                                printf("Player 1 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                            else if (board[i][j] == 'O') {
                                printf("Player 2 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}

/*
This function checks if there in a win in the diagonal starting from top left to bottom right.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void Diagonal270Degrees(char** board, int winNum, int numRows, int numCols) {
    int increment = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 1; j < numCols + 1; ++j) {
            if (board[i][j] == 'X' || board[i][j] == 'O' ) {
                increment = 1;
                for (int k = 1; (i + k <= numRows) && (j + k <= numCols + 1) ; ++k) {
                    if (board[i + k][j + k] == board[i][j]) { //Just like 45 except this time it goes down this way >> '\'
                        increment += 1;
                        if (increment >= winNum) {
                            if (board[i][j] == 'X') {
                                printf("Player 1 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                            else if (board[i][j] == 'O') {
                                printf("Player 2 Won!\n");
                                FreeBoard(board, numRows);
                                exit(0);
                            }
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }   
}

/*
This function checks if there is a win along any of the diagonals: 45 degree or 270 degree.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void DiagonalWin(char** board, int winNum, int numRows, int numCols) {
    Diagonal45Degrees(board, winNum, numRows, numCols); //calls the / direction win function
    Diagonal270Degrees(board, winNum, numRows, numCols); //calls the '\' direction win function
}

/*
This function checks if there is a win in any 4 ways - vertical, horizontal, 45 diagonal, 270 diagonal or is there is a tie.
@param board is a 2D array representing the board
@param winNum is the number of pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return none
*/
void CheckWin(char** board, int winNum, int numRows, int numCols) {
    HorizontalWin(board, winNum, numRows, numCols); //calls the horizontal win function
    VerticalWin(board, winNum, numRows, numCols); //calls the vertical win function
    DiagonalWin(board, winNum, numRows, numCols); //calls the diagonal win function
    Tie(board, winNum, numRows, numCols); //calls the tie function
}