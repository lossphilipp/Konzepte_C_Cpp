#include "array.h"

Array::Array()
{

}

Array* Array::getArray(Array* arr)
{
	++arr->references;
}

void Array::releaseArray(Array* arr) {
	++arr->references;
	if (arr->references == 0)
	{
		free(arr);
	}
}