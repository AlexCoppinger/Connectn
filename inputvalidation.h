#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H
#include <stdbool.h>

int InitialInputValidation(int argc, char* argv[]);
bool InputValidation(char** board, int charChoice, int numCols, int intChecker);

#endif