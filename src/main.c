#include "file.h"
#include "mem.h"

int main(int argc, char* argv[]) {

	//initialize mem array to store malloc returns
	mem* _mem = malloc(sizeof(mem));
	_mem->len = 0;

	txtFile* _txtFile = openFile(argv[1]);
	addmem(_mem, _txtFile);
	printf("%s", _txtFile->buffer);
	free(_txtFile);
	free(_mem);
	printf("%s", "Done");

	return 0;
}