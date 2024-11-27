#include <iostream>
#include <string>

using namespace std;

class X {
private:
	string _name;

public:
	X(const string& name) : _name(name) {
		cout << "X::X(" << _name << ")" << endl;
	};

	~X() {
		cout << "X::~X(" << _name << ")" << endl;
	};

	void f() {
		cout << "X::f(" << _name << ")" << endl;
	}
};

unique_ptr<X> create(const string& name) {
	cout << "create " << name << endl;
	return make_unique<X>(name);
}

void doSomething(unique_ptr<X> pX) {
	if (pX == nullptr) {
		cout << "pX has no memory" << endl;
	}
	else {
		pX->f();
	}
}

int main()
{
	// classic pointer
	X* pX = new X("x1");
	delete pX;

	// unique pointer
	auto pX2 = make_unique<X>("x2");
	if (pX2 == nullptr) {
		cout << "pX2 has no memory" << endl;
	} else {
		pX2->f();
	}
	pX2 = nullptr;

	auto pX3 = create("x3");
	doSomething(pX3);

	// shared pointer
	auto pX4 = make_shared<X>("x4");
	if (pX4 == nullptr) {
		cout << "pX4 has no memory" << endl;
	} else {
		pX4->f();
	}

	cout << "End" << endl;
	return 0;
}