#include "err.h"
#include <stdio.h>
#include <stdlib.h>

char* ERROR_STR[] = {
	[NO_ERROR] = "No error",
	[OUT_OF_MEMORY] = "Out of memory",
	[OPEN_FILE_ERR] = "Error opening file"
};

void err(int errcode) {
	printf("%s", ERROR_STR[errcode]);
	exit(1);
}