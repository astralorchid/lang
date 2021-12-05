#include "lexer.h"

bool strcmp(char* s0, char* s1) {
	uint64_t i = 0;
	for (i; s0[i] != '\0'; i++)
	{
		if (s0[i] != s1[i]) { return false; }
	}
	if (s0[i] == s1[i]) { return true; }
	else { return false; }
}