#include "Stack.h"

int Stack::pop() {
	_data.pop_front();
};

Stack Stack::push(int value) {
	_data.push_front(value);
	return *this;
}