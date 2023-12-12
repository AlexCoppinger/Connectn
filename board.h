#ifndef BOARD_H
#define BOARD_H

char** SetupBoard(int numRows, int numCols);
void PrintBoard(char** board, int numRows, int numCols);
void FreeBoard(char** board, int numRows);

#endif