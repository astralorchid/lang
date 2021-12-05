#include "mem.h"
#include <stdlib.h>

#define OUT_OF_MEMORY "Out of memory"

void addmem(mem* _mem, uintptr_t newptr) { //adds malloc return to array
	uintptr_t* _memptrs; //ptr for resized array
	uintmax_t* len = &_mem->len;
	(*len)++;
	_memptrs = realloc(_mem->ptrs, *len); //resize array
	if (_memptrs != 0) {
		_memptrs[*len - 1] = newptr; //append
	}
	else {
		printf(OUT_OF_MEMORY);
	}
}

mem* initmem() {
	size_t mem_s = sizeof(mem);
	size_t memptrs_s = sizeof(uintptr_t);
	mem* _mem = malloc(mem_s);
	mem* ret = 0;

	if (_mem != 0) {
		uintptr_t* _memptrs = malloc(memptrs_s);
		if (_memptrs != 0) {
			_mem->ptrs = _memptrs;
			_mem->len = 0;

			addmem(_mem, _mem, mem_s);
			addmem(_mem, _memptrs, memptrs_s);
			ret = _mem;
		}
		else {
			printf(OUT_OF_MEMORY);
		}
	}
	else {
		printf(OUT_OF_MEMORY);
	}
	return ret;
}

