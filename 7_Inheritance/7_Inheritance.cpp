#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

// ohne "*" passiert object slicing!
void foo(Shape* s) {
    s->draw();
}

int main()
{
    Shape s;
    Rectangle r;

    s.draw();
    r.draw();

    Shape* pShape = new Rectangle();
    pShape->draw();

    delete pShape;

    return 0;
}