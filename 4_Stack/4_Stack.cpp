#include "stack.h"
#include <iostream>
using namespace std;

void zap(Stack s) { // fehlerhafter Aufruf (kein "&")
    cout << "zap" << endl;
    s.isEmpty();
    s.push(0);
}

void bar(Stack& s) {
    cout << "bar" << endl;
    s.push(0);
    s.isEmpty();
}

void foo(const Stack& s) {
    cout << "foo" << endl;
    s.isEmpty();
    // s.push(0); // nicht möglich weil const
}

int main()
{
    cout << "Main: Begin" << endl;

    Stack stack1(10);
    foo(stack1);
    bar(stack1);

    Stack stack2(20);

    stack2 = stack1;

    cout << "Main: End" << endl;
    return 0;
}