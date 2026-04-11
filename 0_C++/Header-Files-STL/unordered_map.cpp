// Map              
// RBT                  
// Key-Value Pair Sorted
// No duplicate

// U-Map
// NOT sorted
// Hashing (Data stored in buckets)
// NO duplicate

// NOTES: ----------------------------------------------------------------------------------------
// 0. std::unordered_map is an associative container that contains key-value pairs with unique keys.

// 1. Search, insertion, and removal have average constant-time complexity.
// 2. Internally, the elements are organized into buckets.
// 3. It uses hashing to insert elements into buckets.
// 4. This allows fast access to individual elements, because after computing the hash of the value it refers to
//    the exact bucket the element is placed into.

// WHY UNORDERED MAP
// Fastest average-case insertion and removal (O(1)).

// MAP - Fast insertion and removal (O(log n)), but not the fastest.


// PROGRAM:
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, char> umap = {{1, 'a'}, {2, 'b'}};
    // Access
    cout << umap[1] << endl;
    cout << umap[2] << endl;

    // Update
    umap[1] = 'c';

    // Iterate 
    for (auto& elm : umap) {
        cout << elm.first << " " << elm.second << " ";
    }
    cout << endl;

    // Find ----------------------------------------------------------------------
    auto result = umap.find(2);

    if (result != umap.end()) {
        cout << "Found " << result->first << " " << result->second << '\n';
    } else {
        cout << "Not found\n";
    }

    return 0;
}

// U-map - uses hash table 
// Lookup: O(1). worst-case lookup can be slow (O(n)) if many items end up in the same bucket (a "hash collision").
// Bit more memory

// map - sorted first then (Balanced Binary Search Tree) like a red-black tree
// Lookup: O(log n)
// Uses more memory - storing the elements themselves and the tree structure (pointers to children nodes).

// FIND
    // if (mp.find(k) != mp.end()) {
    //     int key = mp.find(k)->first;  // Extracts the key
    //     int value = mp[k];            // Extracts the value
    //     cout << "Key: " << key << ", Value: " << value << endl;
    // }

// Foreach loop
    // for (auto & [num, count] : freq) {
    //     for (int i = 0; i < count; i++) {
    //         remaining.push_back(num);
    //     }
    // }

    // for(auto [ch, count] : freq){
    //     if(wordFreq[ch] < count){
    //         isValid = false;
    //         break;
    //     }
    // }

    // mp["apple"] = 5;
    // mp["banana"] = 3;

    // // Method 2: Using insert with make_pair
    // mp.insert(make_pair("orange", 7));

    // // Method 3: Using initializer list
    // mp.insert({ "grape", 4 });
