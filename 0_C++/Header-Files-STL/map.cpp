// Feature	                map	            unordered_map
// Ordering	                Sorted by key	Unordered (hash table)
// Lookup Speed	            O(log n)	    Average O(1), worst-case O(n)
// Insertion/Deletion	    O(log n)	    Average O(1), worst-case O(n)
// Memory Usage	           Typically less	Typically more

// Keys are immutable once element is inserted
// Why - sorted in order based on key

// Key, value
// No duplicates
// make_pair

// 1. Syntax: map<T1, T2> obj; // where T1 is key type and T2 is value type.
// 2. std::map is associative container that store elements in key value combination
// where key should be unique, otherwise it overrides the previous value.

// 3. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree).
// 4. It store key value pair in sorted order on the basis of key (assending/decending).

// 5. std::map is generally used in Dictionay type problems.

#include <iostream>
#include <map>
#include <functional>
#include <vector>
using namespace std;

// example custom comparator
struct cmp {
    bool operator()(int a, int b) const {
        // return true if a should come **after** b (like descending)
        return a > b;
    }
};

int main() {
    map<string, vector<int>, less<> > Map;

    // default comparator std::less<Key> (which sorts ascending by key).
    // greater<> → descending

    // Map["Macoy"] = 90909009;
    // Map["Dano"] = 982349819;
    // Map["Ralph"] = 982349819;

    Map["Macoy"].push_back(90909009);
    Map["Dano"].push_back(846484884);
    Map["Ralph"].push_back(782349819);

    // Insert Pair Value
    Map["Zoo Person"] = {982348818}; 

    // Loop through map
    for (auto& ell : Map) {
        cout << ell.first << endl;
        for(auto &el2: ell.second){
            cout << el2 << " ";
        }
        cout << endl;
    }

    // Access using [] operator
    // cout << Map["Chotu"] << endl;

    return 0;
}

// less (default) ascending
// greater => Descending

// If you have key integer number, Use map
// In this case, strings are based lexicographically.

// m[key]: Access or insert key-value pair.
// m.find(key): Get iterator to key or m.end() if not found.
// m.count(key): Check if key exists (returns 1 or 0).
// m.erase(key): Remove key-value pair.
// m.size(), m.empty(): Get size and check emptiness.
// m.clear(): Remove all elements.

// Access Method is .first OR .second