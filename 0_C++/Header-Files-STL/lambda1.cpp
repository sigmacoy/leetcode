// Anonymous function without actually having to create a function
// Quick disposable function in c++
// cpp reference lambda expressions

// Unlike regular functions, lambdas do not have an explicit function name or type. 
// Instead, they generate an anonymous function object (a functor). The compiler automatically deduces its type.

// auto is because lambdas do not have a fixed type in C++.

// auto tells the compiler: "Deduce the type of this lambda function object automatically."

// Without auto, you would have to explicitly declare a function pointer or use std::function, which is unnecessary in most cases.

// ALTERNATIVE:
// function<int(int)> sumOfDigits = [](int n) {

// put ; after every { } like };


// Capture	Meaning
// []	Captures nothing. Use only local parameters or global variables.
// [=]	Captures all variables from the enclosing scope by value.
// [&]	Captures all variables from the enclosing scope by reference.
// [a]	Captures only a by value.
// [&a]	Captures only a by reference.
