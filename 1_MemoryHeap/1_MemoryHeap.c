// <> includes fuer standardlibrarys
#include <inttypes.h>
#include <stdio.h>

// "" includes projektspezifisch
#include "mem.h"

int main(int argc, char** argv) {
	int* pValues = mem_malloc(1);

	pValues[0] = 10;

	printf("%d", *pValues);

	return 0;
}