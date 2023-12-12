#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"


/*
You setup your board: 
You change your board depending on the person (if you're person x, you allocate x to array[0][1])
now your board looks like this in the code: *x*
then you print your board 
Then you check if there's a win
*/

/* This function sets up the board for this program.
@param int numRows is the number of rows entered by the user
@param int numCols is the number of rows entered by the user
@returnType is a character pointer pointer. This function returns a 2D array representing the game board.
@return The initialized game board which is a 2D array.
*/
char** SetupBoard(int numRows, int numCols){ //This function initializes and sets up the blank board
    int holderValue;
    char** board = (char**)malloc((numRows + 1) * sizeof(char*)); //Because you have an extra collumn for printing numbers, you need +1
    for(int i = 0; i < (numRows + 1); ++i){
        board[i] = (char*)malloc((numCols + 1) * sizeof(char)); //Because you have an extra collumn for printing numbers at the bottom, you need +1
    }

    for(int j = 0; j < numRows; ++j){ //Because there is an extra rows, you leave it at numRows
        holderValue = (numRows - 1) - j;
        board[j][0] = holderValue + '0';
    }

    for(int k = 0; k < numCols; ++k){ //Because there is an extra column, you need to slide it to the right, and get rid of the last one
        board[numRows][k + 1] = k + '0';
    }
    
    for(int m = 0; m < numRows; ++m){ //Starting from the top, the dimensions of numRows is just the right size for the * signs
        for(int n = 0; n < numCols; ++n){ //Starting from one from the left the number of rows starts to get just the right size of *
            board[m][(n + 1)] = '*';
        }
    }
    board[numRows][0] = ' ';

    return board;
}

/* This function prints the board at the beginning and after each move by the user
@param int numRows is the number of rows entered by the user
@param int numCols is the number of rows entered by the user
@returnType is void(no return value)
@return prints the contents inside the board
*/
void PrintBoard(char** board, int numRows, int numCols){ //This function prints the board
    
  //This for loop prints the contents of the board by taking in 
  //All the arrays on the board will be allocatd with the proper char
  //first print first row, then \n, then print second row...
  for (int i = 0; i < numRows + 1; ++i){ // + 1 to rows and columns because there's an extra of each on the 2D array
    for (int j = 0; j < numCols + 1; ++j){
      printf("%c ", board[i][j]); //Print each iteration
    }
    printf("\n");
  }
}

/* This function frees the board after each user move to avoid memory leak.
@param board is a 2D array representing the board
@param numRows is the number of rows by the user
@returnType void means no return value
@return none.
*/
void FreeBoard(char** board, int numRows) {
    for (int i = 0; i < numRows + 1; ++i) { //the for loop iterates through each row on the board
        free(board[i]);  // Frees the memory allocated for each row
    }
    free(board); // Free the memory allocated for the array of row pointers
}