#include "file.h"
#include "lexer.h"
#include "err.h"

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

txtFile* openFile(char* filename) {
	uint32_t nameLen = (uint32_t)strlen(filename);
	txtFile* newTxtFile = malloc(sizeof(txtFile));
	if(newTxtFile!=NULL){
		newTxtFile->fileName = malloc(nameLen + 1);
		if(newTxtFile->fileName!=NULL){

			for (uint32_t i = 0; i < nameLen; i++) {
				newTxtFile->fileName[i] = filename[i];
			}
			newTxtFile->fileName[nameLen] = '\0';

			FILE* fp = fopen(filename, "r");
			if (fp != NULL) {


				uint32_t fs = getFileSize(fp);
				if (fs > 0) { //if file size > 0
					newTxtFile->fileSize = fs + 2;
					newTxtFile->buffer = malloc(sizeof(char) * fs + 2);

					if (newTxtFile->buffer != NULL) {
						newTxtFile->buffer[0] = 0x0A;
						newTxtFile->buffer[fs + 1] = 0x0A;
						newTxtFile->buffer[fs + 2] = 0;
						for (uint32_t i = 1; i < fs + 1; i++) {
							newTxtFile->buffer[i] = getc(fp);
						}
					}
					else { 
						fclose(fp);
						err(OUT_OF_MEMORY);
					}
				}
				fclose(fp);

			}else{ err(OPEN_FILE_ERR); }
		}
		else { err(OUT_OF_MEMORY); }
	}
	else { err(OUT_OF_MEMORY); }

	return newTxtFile;
}