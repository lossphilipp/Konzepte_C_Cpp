#pragma once
#include <list>
using namespace std;

class Stack
{
private:
	list<int> _data;

public:
	Stack push(int value);
	int pop();
};