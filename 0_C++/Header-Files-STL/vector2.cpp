#include <iostream>
#include <vector>

using namespace std;

// PROBLEM in Vector
// access time O(n); While array access time is O(1)

int main() {
    vector<int> Vec;
    for (int i = 0; i < 32; i++) {
        Vec.push_back(i);
        cout << Vec.size() << " " << Vec.capacity() << endl;
    }
    return 0;
}

// vec.reserve(1000);

// .find() in vector
    // #include <algorithm>

    //     vector<int> vec = {4, 1, 2, 3, 4, 2, 3};
    //     int target = 2;

    //     auto it = find(vec.begin(), vec.end(), target); 

    //     if (it != vec.end()) {
    //         cout << "Found " << target << " at index " << it - vec.begin() << endl; // 
    //     } else {
    //         cout << "Not found" << endl;
    //     }

    //     return 0;
    // }

    // .find() in vector (SECOND WAY)
    

// Vector to Int
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // int result = 0;
    // for (auto d : v)  
    // {
    //     result = result * 10 + d;
    // }


