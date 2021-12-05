#include "file.h"
#include "lexer.h"
uint32_t getFileSize(FILE* fptr) {
	char c;
	uint32_t fileSize = 0;
	c = getc(fptr);
	while (c != EOF) {
		fileSize += 1;
		c = getc(fptr);
	}
	rewind(fptr);
	return fileSize;
}

txtFile openFile(char* filename) {
	uint32_t nameLen = (uint32_t)strlen(filename);
	txtFile* newTxtFile = malloc(sizeof(txtFile));
	newTxtFile->fileName = malloc(nameLen + 1);
	for (uint32_t i = 0; i < nameLen; i++) {
		newTxtFile->fileName[i] = filename[i];
	}
	newTxtFile->fileName[nameLen] = '\0';
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		newTxtFile->fileSize = 0;
		return *newTxtFile;
	}

	uint32_t fs = getFileSize(fp);
	if (fs > 0) { //if file size > 0
		newTxtFile->fileSize = fs+2;
		newTxtFile->buffer = malloc(sizeof(char) * fs + 2);

		if (newTxtFile->buffer != NULL) {
			newTxtFile->buffer[0] = 0x0A;
			newTxtFile->buffer[fs + 1] = 0x0A;
			newTxtFile->buffer[fs + 2] = 0;
			for (uint32_t i = 1; i < fs + 1; i++) {
				newTxtFile->buffer[i] = getc(fp);
			}
		}
	}
	fclose(fp);
	return *newTxtFile;
}