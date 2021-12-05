#include "file.h"
#include "mem.h"

int main(int argc, char* argv[]) {
	//initialize mem array to store malloc returns
	mem* _mem = initmem();

	txtFile* _txtFile = openFile(argv[1]);
	addmem(_mem, _txtFile);

	printf("%s", _txtFile->buffer);
	printf("Malloc return array size: %d\n", (int)_mem->len);

	return 0;
}