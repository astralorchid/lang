#ifndef FILE_H
#define FILE_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* buffer;
	char* fileName;
	uint32_t fileSize;
}txtFile;

uint32_t getFileSize(FILE* fptr);
txtFile openFile(char* filename);

#endif
