#include <iostream>
#include <string>
// #include <string_view> // C++ 17

using namespace std; 

int main() {
    string str_1{ "Hello!!, This is Macoy" };

    // string_view str_2{ str_1.substr(0, 5) }; 
    // string_view str_3{ str_2 };

    cout << str_1 << '\n';
    // cout << str_2 << '\n';
    // cout << str_3 << '\n';

    return 0;
}

// string substr (size_t pos, size_t len) const;