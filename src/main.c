#include "file.h"
#include "mem.h"
#include "lexer.h"
#include "err.h"

int main(int argc, char* argv[]) {
	txtFile* _txtFile = openFile(argv[1]);
	tok* tokens = tokenize(_txtFile->buffer, _txtFile->fileSize);
	return 0;
}