#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputvalidation.h"

/*

When you run the program, you must include the arguments 
arg

File list:
board.c/h
-require array pointer: a[rows][columns]

connectn.c/h
- 

inputvalidation.c/h
-Too few or too many arguments or invalid --> Complain
-Must be 3 valid inputs --> must be intereges
-All inputs numbered

Read inputs in ./connectn x y z
x being rows
y being columns
z pieces to win

If these conditions are not met: 

3 4 i --> Too few inputs because i is not an integer

play.c/h
-Player 1 is x
-Player 2 is O
-1 goes first 

win.c/h
-Number of pieces in a row needed to win --> Number of pieces can be larger than on board (This would mean you can't win?)
-No winner tie is declared
-Winner say "winner!"

*/

/*This function goes over the command line arguments that is inputted. There has to be only 3 arguments and those 3 must be digits greater than 0.
@param argc is the number of command line arguments
@param argv an array of pointers to arrays of character objects
@returnType: An integer (0 if validation is successful)
@return: 0 if the arguments are valid, otherwise it prints an error message and exits.
*/
int InitialInputValidation(int argc, char *argv[]) { //input num should be 3. It's this way so that this function can be reusable for future programs) This one is to check whether they're digits
    if (argc > 4) { //this if statements is if the user enters more than required number of arguments
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    if (argc < 4) { //this if statements is if the user enters less than required number of arguments
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    for (int i = 1; i < 4; ++i) { //this for loop iterates through all of teh command lien arguments
		if (isdigit(*argv[i]) == 0) {
            printf("invalid argument entered\n");
            printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
            exit(0);
        }

        int value = atoi(argv[i]); //converts the i-th command line to an integer value
        if(value <= 0) {
            printf("invalid argument entered\n");
            printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
            exit(0);
        }
    }
    return 0;
}

/*This function validates user input for placing a piece (X or O) in the game board. It checks a)if the column is greater than 0 b) whether column is not full c)input is a valid integer
@param board is the 2D array representing the board
@param numCols is the number of columns the user entered
@param colChoice is the column that they want to input their X or O in.
@param intChecker is an indicator for whether the input is a valid integer (1 if true, 0 if false)
@returnType: true if the arguments pass the checks, false if otherwise
@return true of the input passes all of the tests
*/
bool InputValidation(char** board, int colChoice, int numCols, int intChecker) {
    bool validInput = false;
        if(colChoice < 0 || colChoice > numCols) { //Makes sure the number is within the bounds of the board (horizontally)
            validInput = false;
        }
        else if(board[0][colChoice + 1] == 'X' || board[0][colChoice + 1] == 'O'){ //Makes sure the column isn't filled up yet
            validInput = false;
        }
        else if(intChecker != 1) { //Makes sure what is input is not a character but an integer
            validInput = false;
        }
        else {
            validInput = true;
        }

    return validInput;
}