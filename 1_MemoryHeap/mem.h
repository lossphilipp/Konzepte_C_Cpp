//#pragma once

#ifndef HEAP_SIZE
#define HEAP_SIZE 1024
#endif

#ifndef FREE
#define FREE 'F'
#endif

#ifndef ALLOCATED
#define ALLOCATED 'A'
#endif

#ifndef RFU
#define RFU 0x0
#endif

#ifndef MEM_H__
#define MEM_H__

#include <inttypes.h>

void* mem_malloc(uint16_t size);
void* mem_free(void* adress);

#endif