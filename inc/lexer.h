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
	uintmax_t len;

} token;
#endif
