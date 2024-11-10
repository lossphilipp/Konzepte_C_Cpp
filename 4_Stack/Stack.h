#pragma once

class Stack
{
private:
	int* _pValue;
	int _size;

public:
	Stack(int size);
	Stack(const Stack& other); // copy-ctor benoetigt immer zuweisungs-ueberschreibung (stack1 = stack2)
	Stack& operator=(const Stack& s);

	~Stack();

	void push(int i) {};

	bool isEmpty() const { // "const" sagt dem compiler das das objekt nicht verändert wird
		return true;
	}
};