#include <iostream>
using namespace std;

int main(){
    int a = 1, b = 2, c = 3;

    // Capture NOTHING - can't use a, b, c
    auto lambda1 = []() { return 42; };

    // Capture ALL by VALUE
    auto lambda2 = [=]() { return a + b; }; // gets copies of a and b

    // Capture ALL by REFERENCE
    auto lambda3 = [&]() { c = 99; }; // can modify original c

    // Capture ONLY 'a' by VALUE and 'b' by REFERENCE
    auto lambda4 = [a, &b]() { b = a + 10; }; // a is copy, b is reference

    // Capture ALL by value, but 'c' by REFERENCE
    auto lambda5 = [=, &c]() { c = a + b; }; // a,b are copies, c is reference

    // Capture ALL by reference, but 'a' by VALUE
    auto lambda6 = [&, a]() { b = a + c; }; // a is copy, b,c are references

}

/*
    Lambdas translated into functors...
    A functor (or function object) is a C++ class that acts like a function. Functors are called using the same old function call syntax.

Types of Capture Clauses:
[] (Capture nothing)
The lambda cannot use any external variables. It can only use its parameters and static variables.

[=] (Capture by value)
The lambda gets a copy of all external variables it uses.

[&] (Capture by reference)
The lambda gets access to (a reference to) all external variables it uses. Changes inside the lambda affect the original.

[var] (Capture specific variable by value)
Capture only var by value.

[&var] (Capture specific variable by reference)
Capture only var by reference.

Mixed Captures
You can mix them: [=, &var] (capture everything by value, but var by reference).

When to Use Which:
Use [ ] if the lambda is self-contained.

Use [=] or [&] for quick, simple lambdas (but be cautious with [&] and dangling references).

For clarity and safety, prefer explicit captures ([a, &b]) over implicit ones ([=], [&]).

Be especially careful with [&] if the lambda might outlive the current scope 
(e.g., stored or passed to another thread). This can cause dangling references.

*/