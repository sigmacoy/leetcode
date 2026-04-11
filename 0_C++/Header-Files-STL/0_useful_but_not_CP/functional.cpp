// functional
// Function wrappers and utilities
// C++ standard functional programming header

// NOTES:
// 0. Provides std::function (polymorphic function wrapper)
// 1. Provides std::bind (partial function application)
// 2. Provides std::ref, std::cref for reference wrapping
// 3. Provides function adapters and negators

// WHY FUNCTIONAL
// Store lambdas in variables, pass functions as arguments, create callbacks.

// PROGRAM:
#include <functional>
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int main() {
    // Store function in variable
    function<int(int, int)> func = add;
    cout << func(3, 5) << endl;
    
    // Store lambda
    function<int(int, int)> lambda = [](int x, int y) { return x * y; };
    cout << lambda(3, 5) << endl;
    
    // Bind with partial arguments
    auto add5 = bind(add, placeholders::_1, 5);
    cout << add5(10) << endl;
    
    return 0;
}

// Common Uses:
// function<int(int, int)>  - Function taking 2 ints, returning int
// bind(func, args...)      - Bind arguments to function
// ref(var)                 - Wrap reference for bind
// placeholders::_1, _2     - Placeholder for unbound arguments