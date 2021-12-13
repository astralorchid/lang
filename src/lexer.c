#include "lexer.h"
#include "err.h"
#include <stdio.h>
#include <stdlib.h>

tok* toke(size_t size) { //alloc mem for token
	tok* _ = malloc(size);
	if (_ != NULL) {
		return _;
	}
	else {
		printf("toke");
		err(OUT_OF_MEMORY);

	}
}

int invalid() {
	err(NOT_ASCII_ERR);
}

char* oomc() {//oom
	err(OUT_OF_MEMORY);
}

char* stralloc(size_t size) {
	
	char* _ = malloc(size);
	if (_ != NULL) {
		return _;
	}
	else {
		printf("stralloc");
		err(OUT_OF_MEMORY);
	}
}

tok* newtok(tok* token, uintmax_t bufpos) { //
	token->bufpos++;
	uintmax_t toklen = token->len;
	uintmax_t strstart = (token->bufpos-toklen);

	char* tokstr = stralloc(sizeof(char)* (toklen + 1));
	token->str = tokstr;

	for (uintmax_t i = 0; i < toklen; i++) {
		tokstr[i] = token->buf[(strstart+i)];
	}
	tokstr[toklen] = '\0';
	printf("%s ", tokstr);

	tok* tokens = realloc(token->parent, sizeof(tok) * (token->index+2));

	tok* _newtok = &tokens[token->index + 1];

	_newtok->buf = token->buf;
	_newtok->bufpos = token->bufpos;
	_newtok->index = token->index+1;

	_newtok->len = 1;
	_newtok->line = token->line;

	for (uintmax_t i = 0; i < _newtok->index + 1; i++) {
		tok* _tok = &tokens[i];
		_tok->parent = tokens;
	}
	_newtok->parent = tokens;	return _newtok;
	//exit(0);
}

tok* ignore(tok* token, uintmax_t bufpos) {
	token->bufpos++;
	token->len++;
	return token;
}
tok* incline(tok* token, uintmax_t bufpos) { //increment token line #
	token->bufpos++;
	token->line++;
	return token;
}

tok* addchar(tok* token, uintmax_t bufpos) { //add char to token
	token->bufpos++;
	token->len++;
	return token;
}

uintptr_t tokfunc[] = {
	[0x0a] = &incline,[0x0d] = &newtok,[' '] = &newtok,[0x9] = &newtok,
	['!'] = &newtok,['"'] = &newtok,['#'] = &newtok,
	['$'] = &newtok,['%'] = &newtok,['&'] = &newtok,
	['\''] = &newtok,['('] = &newtok,[')'] = &newtok,
	['*'] = &newtok,['+'] = &newtok,[','] = &newtok,
	['-'] = &newtok,['.'] = &newtok,['/'] = &newtok,
	['0'] = &addchar,['1'] = &addchar,['2'] = &addchar,
	['3'] = &addchar,['4'] = &addchar,['5'] = &addchar,
	['6'] = &addchar,['7'] = &addchar,['8'] = &addchar,
	['9'] = &addchar,[':'] = &newtok,[';'] = &newtok,
	['<'] = &newtok,['='] = &newtok,['>'] = &newtok,
	['?'] = &newtok,['@'] = &newtok,['A'] = &addchar,
	['B'] = &addchar,['C'] = &addchar,['D'] = &addchar,
	['E'] = &addchar,['F'] = &addchar,['G'] = &addchar,
	['H'] = &addchar,['I'] = &addchar,['J'] = &addchar,
	['K'] = &addchar,['L'] = &addchar,['M'] = &addchar,
	['N'] = &addchar,['O'] = &addchar,['P'] = &addchar,
	['N'] = &addchar,['O'] = &addchar,['P'] = &addchar,
	['N'] = &addchar,['O'] = &addchar,['P'] = &addchar,
	['N'] = &addchar,['O'] = &addchar,['P'] = &addchar,
	['N'] = &addchar,['O'] = &addchar,['P'] = &addchar,
	['Q'] = &addchar,['R'] = &addchar,['S'] = &addchar,
	['T'] = &addchar,['U'] = &addchar,['V'] = &addchar,
	['W'] = &addchar,['X'] = &addchar,['Y'] = &addchar,
	['Z'] = &addchar,['['] = &newtok,['\\'] = &newtok,
	[']'] = &newtok,['^'] = &newtok,['_'] = &newtok,
	['`'] = &newtok,['a'] = &addchar,['b'] = &addchar,
	['c'] = &addchar,['d'] = &addchar,['e'] = &addchar,
	['f'] = &addchar,['g'] = &addchar,['h'] = &addchar,
	['i'] = &addchar,['j'] = &addchar,['k'] = &addchar,
	['l'] = &addchar,['m'] = &addchar,['n'] = &addchar,
	['o'] = &addchar,['p'] = &addchar,['q'] = &addchar,
	['r'] = &addchar,['s'] = &addchar,['t'] = &addchar,
	['u'] = &addchar,['v'] = &addchar,['w'] = &addchar,
	['x'] = &addchar,['y'] = &addchar,['z'] = &addchar,
	['{'] = &newtok,['|'] = &newtok,['}'] = &newtok,
	['~'] = &newtok
};

tok* tokenize(char* buf, uintmax_t buflen) {
	tok* tokens = toke(sizeof(tok));
	tok* thistok = &tokens[0]; 
	thistok->parent = tokens;
	thistok->buf = buf;
	thistok->bufpos = UINT_MAX;
	thistok->len = 0;
	thistok->index = 0;

	for (uintmax_t i = 0; i < buflen; i++) {
		tok*(*toker)(tok*, uintmax_t) = tokfunc[buf[i]];
		thistok = toker(thistok, i);
	}

	uintmax_t toklen = thistok->len;
	uintmax_t strstart = (thistok->bufpos - toklen);

	char* tokstr = stralloc(sizeof(char) * (toklen + 1));
	thistok->str = tokstr;

	for (uintmax_t i = 0; i < toklen; i++) {
		tokstr[i] = thistok->buf[(strstart + i)];
	}
	tokstr[toklen] = '\0';
	printf("%s ", tokstr);
	printf("\n");
	for (uintmax_t i = 0; i < thistok->index+1; i++) {
		tok* _tokens = thistok->parent;

		tok* test = &_tokens[i];
		printf("%d ", i);
		printf("token: %s\n",test->str);
	}
	return tokens;
}

bool strcmp(char* s0, char* s1) {
	uintmax_t i = 0;
	for (i; s0[i] != '\0'; i++)
	{
		if (s0[i] != s1[i]) { return false; }
	}
	if (s0[i] == s1[i]) { return true; }
	else { return false; }
}