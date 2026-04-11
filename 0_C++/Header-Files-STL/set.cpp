

// O(1) -> Implemented by Red-Black Tree = Self-Balancing Binary Search Tree
    // In such a tree, finding an element involves traversing the tree from the root, and in a balanced tree, 
    //  the maximum depth of traversal is logarithmic to the number of elements.

// SYNTAX: std::set<T> obectName;   

// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logirathmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)

#include <iostream>
#include <set>
#include <string>
#include <functional>

using namespace std;

class Person{
    public:
        float age;
        string name;
    
    bool operator < (const Person& rhs) const {
        return age < rhs.age; // Comapre function for less
    }
    
    bool operator > (const Person& rhs) const {
        return age > rhs.age; // Compare fuction for greater
    }
};
    
int main() {
    set<Person, greater<Person>> Set = {{30, "Rupesh"}, {25, "Hitesh"}, {22, "Jhon"}};
    
    for (const auto& e: Set) {
        cout << e.age << " " << e.name << endl;
    }

    return 0;
}

// Feature	        <set>	                        <map>
// What it stores	Unique elements(keys only)	    Key-value pairs
// Uniqueness	    Elements must be unique	        Keys must be unique
// Sorting	        Sorted by element value	        Sorted by key
// Use case	        Storing unique values	        Storing associations (dictionaries, etc.)

// s.insert(x): Insert element.
// s.erase(x): Remove element.
// s.find(x): Get iterator to x or s.end() if not found.
// s.count(x): Check if x exists (1 or 0).
// s.lower_bound(x), 
//  s.upper_bound(x): Get iterators for ordered sets.

//  s.upper_bound(x) != s.end();


// INSERT (NO PUSH_BACK in SETS) !!! ==> Use s.insert();
    // set<int> s = {1, 3, 5}; 

    // // Insert a single element
    // s.insert(2);

    // // Insert multiple elements
    // s.insert({4, 6, 7});

    // // Insert and check if insertion was successful
    // auto result = s.insert(3); // NOTE: 3 is already present!
    // if (!result.second) {
    //     std::cout << "Element already exists!\n";
    // }

// Multiset
    // #include <iostream>
    // #include <set>
    // using namespace std;

    // int main() {
    //     multiset<int> ms = {30, 10, 20, 10, 30, 20};

    //     for (int x : ms) {
    //         cout << x << " ";  // Output: 10 10 20 20 30 30
    //     }
    //     return 0;
    // }

// set<int> does not support subscripting ([])
    // set<int> s;
    // s.insert(5);
    // if (s.count(5)) {  // Correct way to check existence
    //     cout << "5 is present\n";
    // }