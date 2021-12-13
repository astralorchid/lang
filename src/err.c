#include "err.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

char* ERR_STR[] = {
	[NO_ERR] = "No error",
	[OUT_OF_MEMORY] = "Out of memory",
	[OPEN_FILE_ERR] = "Error opening file",
	[NOT_ASCII_ERR] = "Error: ASCII value out of bounds (invalid character)"
};

void err(int errcode) {
	printf("%s", ERR_STR[errcode]);
	exit(1);
}

void tok_err(tok* token, int errcode) {
	printf("%s", ERR_STR[errcode]);
	//printf("%s", tok->str);
	exit(1);
};