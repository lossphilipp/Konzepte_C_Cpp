#pragma once
#include <list>
using namespace std;

class Stack_inh : private list<int>
{
public:
	void push(int value) {
		push_front(value);
	}
};