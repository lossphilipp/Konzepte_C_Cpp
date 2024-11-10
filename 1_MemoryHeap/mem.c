#include "mem.h"

typedef struct {
	uint8_t flag;
	uint8_t rfu;
	uint16_t len;
} mem_header_t;

static uint8_t gHeap[HEAP_SIZE];

// ToDo: When do i call this?
static void* InitHeap(void* heapLocation)
{
	mem_header_t* initHeader = heapLocation;

	initHeader->flag = FREE;
	initHeader->rfu = RFU;
	initHeader->len = HEAP_SIZE - sizeof(mem_header_t);

	return initHeader;
}

static void* TryMergeWithNextFreeHeader(mem_header_t* location, uint16_t previosLength)
{
	mem_header_t* newHeader = (uint8_t*)location + previosLength + 1;

	if (newHeader->flag != FREE)
	{
		return newHeader;
	}

	newHeader->flag = FREE;
	location->len = location->len + newHeader->len + sizeof(mem_header_t);

	return location;
}

static void* TryCreateNextHeader(void* location, uint16_t previosLength)
{
	mem_header_t* oldHeader = location;
	mem_header_t* newHeader = (uint8_t*)oldHeader + previosLength + 1;

	if (newHeader >= ((uint8_t*)gHeap + sizeof(gHeap)))
	{
		return oldHeader;
	}

	if (oldHeader->len == previosLength)
	{
		return oldHeader;
	}

	newHeader->flag = FREE;
	newHeader->rfu = RFU;
	newHeader->len = previosLength - oldHeader->len - sizeof(mem_header_t);

	TryMergeWithNextFreeHeader(location, newHeader->len);

	return newHeader;
}

void* mem_malloc(uint16_t size)
{
	mem_header_t* pHeader = gHeap;

	while (pHeader < ((uint8_t*)gHeap + sizeof(gHeap)))
	{
		if (pHeader->flag == FREE && pHeader->len >= size)
		{
			uint16_t originalLength = pHeader->len;

			pHeader->flag = ALLOCATED;
			pHeader->rfu = RFU;
			pHeader->len = size;

			TryCreateNextHeader(
				pHeader,
				originalLength
			);

			return pHeader + 1;
		}

		pHeader = (uint8_t*)(pHeader + 1) + pHeader->len;
		// pHeader = (uint8_t*)pHeader + sizeof(mem_header_t) + pHeader->len;
	}

	return NULL;
}

void* mem_free(void* addr)
{
	mem_header_t* header = addr;
	header->flag = FREE;

	TryMergeWithNextFreeHeader(header, header->len);

	return header;
}
