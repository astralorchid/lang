#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include <stdio.h>
typedef struct {
	char* buffer;
	char* fileName;
	uintmax_t fileSize;
}txtFile;

uintmax_t getFileSize(FILE* fptr);
txtFile* openFile(char* filename);

#endif
