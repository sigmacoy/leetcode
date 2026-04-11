
// O(1) -> Implemented by Hashmap

// unorder set - contains set of unique objects
// use of hashing ==> data into buckets concept THEN query O(1) look up

// 2. Internally, the elements are organized into buckets.
// 4. This eulous fast a case to indevidual a lucket, since once a hash is computed.
// 5. it refers to the exact bucket the element is placed into.

// why?
// maintain a collection of unique items with fast insertion and removal.

// need const in a for each loop -> sets are immutable in C++

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> uset = {4, 1, 2, 3, 4, 2, 3};
    auto search = uset.find(2);

    if (search != uset.end()) { 
        cout << "Found " << *search << '\n'; 
    } else {
        cout << "Not found\n";
    }

    for (auto& elm : uset) {
        cout << elm << " ";
    }

    cout << endl;

    return 0;
}

// output is not in sorting order but unique

// Unordered_set<int> u_set = {1, 2, 3, 4, 5};
    // cout << "Count of 3: " << u_set.count(3) << endl; // ✅ Output: 1 (3 exists)
    // cout << "Count of 6: " << u_set.count(6) << endl; // ✅ Output: 0 (6 does not exist)
    // return type is 0 or 1

// .find() returns the iterator

// set to vector
    // v.assign(s1.begin(), s1.end());
    // v.assign(s2.begin(), s2.end());

// if you print u_set ==> it will randomly print daw. But eventually printed it in descendingly.

