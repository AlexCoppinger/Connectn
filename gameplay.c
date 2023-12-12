#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameplay.h"
#include "board.h"
#include "win.h"
#include "inputvalidation.h"

/*
This function is the main loop for playing the game. It alternates between players, takes user input, validates the input, updates & prints the board, and checks for a win or tie.
@param board is a 2D array representing the game board
@param winNum is the number of consecutive pieces needed to win
@param numRows is the number of rows on the board
@param numCols is the number of columns on the board
@returnType void means no return value
@return The function does not return; it exits the program when the game ends.
*/
void PlayGame(char** board, int winNum, int numRows, int numCols){
	/*This function is one big 'ol loop that plays a turn, validates an input, 
	prints the board, then checks for a win or tie, and ends the program if there is one*/ 
	int colChoice; //The choice of column to play in for the player
	char player1 = 'X';
	char player2 = 'O';
	int whichPlayer = 0;
	int rowNum; //Used to tell how many rows up from the bottom your piece will be put
	int intChecker; //Checks how many integers have been input

	while (1) { //This is just so that the while loop keeps iterating (once there's a win or tie, the program will end)
		CheckWin(board, winNum, numRows, numCols);
		printf("Enter a column between 0 and %d to play in: ", (numCols - 1));
		intChecker = scanf("%d", &colChoice);
		
		while(InputValidation(board, colChoice, (numCols - 1), intChecker) == false) { //This is to check the input is valid
			while (getchar() != '\n'); //This makes ot so that nothing is read afterwards
			printf("Enter a column between 0 and %d to play in: ", (numCols - 1));
			intChecker = scanf("%d", &colChoice);
		}

		rowNum = 1; //The firce piece will start above the footer
		while ((board[numRows - rowNum][colChoice + 1]) != '*') { //This loop makes sure the next piece put in is above any other
		rowNum += 1;
		}
		if(whichPlayer % 2 == 0) { //This if statement is to tell which turn its been (for player 1)
			board[numRows - rowNum][colChoice + 1] = player1;
		}
		else if(whichPlayer % 2 == 1) { //If the turn is odd, that means player 2 plays (same concept as the other turn)
			board[numRows - rowNum][colChoice + 1] = player2;
		}
		PrintBoard(board, numRows, numCols); //calls the function to print the board after each user move
		whichPlayer += 1; //increments after each player's move
	}
}