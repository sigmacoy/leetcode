// SYNTAX: std::multiset<T> obectName;

// Multiset allow store duplicates

// 1. std::multiset is an Associative Container that contains a sorted set of duplicate objects of type Key.
// 2. It is usually implemented using Red-Black Tree.

// 3. Insertion, Removal, Search have logirathmic complexity.
// 4. If we want to store user defined data type in multiset then we will have to provide
//    compare function so that multiset can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// multiset is similar to set except it can have multiple elements with same value.

#include <iostream>
#include <set>
#include <string>
#include <functional>
using namespace std;

class Person {
public:
    float age;
    string name;

    bool operator < (const Person& rhs) const {return age < rhs.age;}
    
    bool operator > (const Person& rhs) const {return age > rhs.age;}
    
};

int main() {
    multiset<Person, greater<Person>> multiSet = {{25, "Macoy"}, {20, "Dano"}};
    
    for (const auto& e : multiSet) {
        cout << e.age << " " << e.name << endl;
    }
    return 0;
}

// count() method available - searches for a specific element in the multiset container and returns the number of occurrences of that element.