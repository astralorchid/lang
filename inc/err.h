#ifndef ERR_H
#define ERR_H

#include "lexer.h"

#define NO_ERR 0
#define OUT_OF_MEMORY 1
#define OPEN_FILE_ERR 2
#define NOT_ASCII_ERR 3

void err(int errcode);
void tok_err(tok* token, int errcode);

#endif