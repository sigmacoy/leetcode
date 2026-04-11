#include <iostream>
using namespace std;

int main(){
    int y = 10; // Outside variable

    // Created NOW: captures y's current value (10)
    auto addY = [y](int x) { return x + y; };

    y = 100; // Change original

    // Called LATER: still uses captured y=10
    cout << addY(5); // 15, not 105

    return 0;
}

/*
Capture saves y=10 when lambda is defined.
Parameters (x) are provided when called.

Short summary of symbols in []:

[] → Capture nothing
[=] → Capture all by value
[&] → Capture all by reference
[var] → Capture var by value
[&var] → Capture var by reference
[=, &var] → Capture most by value, but var by reference
[&, var] → Capture most by reference, but var by value

*/