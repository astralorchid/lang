#include "mem.h"
#include "err.h"
#include <stdlib.h>



void addmem(mem* _mem, uintptr_t newptr) { //adds malloc return to array
	uintptr_t* _memptrs; //ptr for resized array
	uintmax_t* len = &_mem->len;
	(*len)++;
	_memptrs = realloc(_mem->ptrs, *len); //resize array
	if (_memptrs != 0) {
		_memptrs[*len - 1] = newptr; //append
	}
	else {
		err(OUT_OF_MEMORY);
	}
}

mem* initmem() {
	mem* _mem = malloc(sizeof(mem));

	if (_mem != 0) {
		uintptr_t* _memptrs = malloc(sizeof(uintptr_t));
		if (_memptrs != 0) {
			_mem->ptrs = _memptrs;
			_mem->len = 0;
			addmem(_mem, _mem);
			addmem(_mem, _memptrs);
		}
		else {
			err(OUT_OF_MEMORY);
		}
	}
	return _mem;
}

