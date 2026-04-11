#include <iostream>
#include <set>
using namespace std;

// s.insert(x): Insert element.
// s.erase(x): Remove element.
// s.find(x): Get iterator to x or s.end() if not found.
// s.count(x): Check if x exists (1 or 0).
// s.lower_bound(x), 
//  s.upper_bound(x): Get iterators for ordered sets.
//  s.upper_bound(x) != s.end();

// Set iterators are bidirectional (can do ++/--) but not random access (can't do + n directly).

int main(){
    std::set<int> s = {30, 10, 20, 40};

    // Method 1: Use std::next
    auto it = s.begin();
    cout << *next(it, 1); // 20

    // Method 2: Increment iterator
    auto it2 = s.begin();
    ++it2; 
    cout << *it2; // 20

    // Method 3: Loop through first N elements          --> Much better than regular for-loop
    int count = 0;
    for(auto elem : s) {
        if(count == 1) { 
            cout << elem; // 20
            break;
        }
        count++;
    }

}

// Bidirectional Iterators (set, map, list)
// Can only do: ++ and --
// Cannot do: + n
    // Why set has Bidirectional Iterators:
    // std::set is implemented as a binary search tree
    // To get to the next element, it must traverse tree nodes (left → root → right)


// std::map is generally implemented using self-balancing binary search trees, most commonly Red-Black Trees.