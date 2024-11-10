#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size) {
	cout << "Stack: regular ctor" << endl;
	_pValue = new int[size];
	_size = size;
}

Stack::Stack(const Stack& other) {
	cout << "Stack: copy ctor" << endl;

	_pValue = new int[other._size];
	_size = other._size;
	for (int i = 0; i < _size; i++)
	{
		_pValue[i] = other._pValue[i];
	}
}

Stack& Stack::operator=(const Stack& other) {
	cout << "Stack: Zuweisungsoperator" << endl;

	if (this == &other) // this ist immer pointer
	{
		return *this;
	}

	delete[] _pValue; // Speicherloch vorbeugen

	_pValue = new int[other._size];
	_size = other._size;
	for (int i = 0; i < _size; i++)
	{
		_pValue[i] = other._pValue[i];
	}

	return *this;
}

Stack::~Stack() {
	cout << "Stack: dector" << endl;
	delete[] _pValue;
}