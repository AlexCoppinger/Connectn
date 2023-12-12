#include <stdio.h>
#include <stdlib.h>
#include "gameplay.h"
#include "inputvalidation.h"
#include "board.h"
/*typedef char** board_tp;
typedef int age_t;*/

/* This is the main function in the program. It declares the rows, columns and board. It takes in user input. It also calls the functions for printing & playing the game. 
@param argc is the number of command-line arguments.
@param argv array of command-line argument strings.
returnType an integer.
return an integer saying the status of the program
*/
int main(int argc, char* argv[]) {
	//char* player_pieces;
	//int player_turn;
	int numRows; //declaring the number of rows
	int numCols; //declaring the number of columns
	int winNum; //declaring the number of pieces of win
	char** board; //allocating space for board
	InitialInputValidation(argc, argv); //Make sure the initial inputs are valid
	
	//Gather the inputs from argv
	sscanf(argv[1], "%d", &numRows); 
	sscanf(argv[2], "%d", &numCols); 
	sscanf(argv[3], "%d", &winNum); 
	
	board = SetupBoard(numRows, numCols); //Setup the char** board
	PrintBoard(board, numRows, numCols); //Print first iteration
	PlayGame(board, winNum, numRows, numCols); //calls the function for playing the game

	return 0;
}
