#ifndef LEXER_H
#define LEXER_H

#include <stdint.h>
//custom bool type
typedef unsigned char bool;
#define false 0
#define true 1

//type structures

typedef struct {
	char* str;
	char* buf;
	uintmax_t len;
	uintmax_t line;
	uintmax_t bufpos;
	uintmax_t index;
	uintptr_t parent;
} tok;

tok* tokenize(char* buf, uintmax_t buflen);

#endif
