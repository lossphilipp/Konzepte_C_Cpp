#pragma once

class Array
{
private:
	int* _pValues;

public:
	int references;

	Array();

	Array* getArray(Array* arr);
	void releaseArray(Array* arr);
};