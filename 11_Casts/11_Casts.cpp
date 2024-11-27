#include <iostream>

class Base {
public:
    // Output different if not virtual
    virtual void display() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void display() override { std::cout << "Derived class\n"; }
};

class AnotherDerived : public Base {};

int main() {
    Base* pBase = new Derived;

    // Works correctly because `base` actually points to a `Derived` object
    Derived* pDerived_static = static_cast<Derived*>(pBase);
    pDerived_static->display();

    // Safe, base points to a Derived object
    Derived* pDerived_dynamic = dynamic_cast<Derived*>(pBase);
    if (pDerived_dynamic) {
        pDerived_dynamic->display();
    }
    else {
        std::cout << "dynamic_cast failed: \"base\" is not \"Derived\"\n";
    }

    // Attempting invalid cast
    AnotherDerived* pAnother_dynamic = dynamic_cast<AnotherDerived*>(pBase);
    if (pAnother_dynamic) {
        pAnother_dynamic->display();
    }
    else {
        std::cout << "dynamic_cast failed: \"base\" is not \"AnotherDerived\"\n";
    }


    Derived* pDerived = (Derived*)pBase;
    pDerived->display();

    delete pBase;
    return 0;
}