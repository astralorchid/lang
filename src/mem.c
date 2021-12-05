#include "mem.h"
#include <stdlib.h>

void addmem(mem* _mem, uintptr_t newptr) {
	mem* __mem;
	uintmax_t* len = &_mem->len;
	(*len)++;
	__mem = realloc(_mem, sizeof(mem)*(*len));	
}

mem* initmem() {
	mem* _mem = malloc(sizeof(mem));
	_mem->ptrs = malloc(sizeof(uintmax_t));
	_mem->len = 0;
	addmem(_mem, &_mem->ptrs);
}