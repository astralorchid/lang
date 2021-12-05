#include "file.h"

int main(int argc, char* argv[]) {
	txtFile _txtFile = openFile(argv[1]);
	printf("%s", _txtFile.buffer);

	printf("%s", "Done");

	return 0;
}