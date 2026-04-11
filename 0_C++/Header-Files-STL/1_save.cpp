#include <iostream>
using namespace std;

struct A {
    void show() const { cout << "Hello\n"; }
};

void print(const A& obj) {
    obj.show(); // allowed
    // obj = ...; // not allowed, cannot modify
}

int main() {
    A a;
    print(a); // passes without copying;  -> Hello
}