#ifndef MEM_H
#define MEM_H

#include <stdint.h>

typedef struct {
	uintptr_t ptrs; //array of stored malloc returns
	uintmax_t len;
} mem;

#endif
