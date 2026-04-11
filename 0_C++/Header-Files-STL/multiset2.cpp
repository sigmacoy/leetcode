/*

Default is sorted ascendingly

*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    
    // Inserting elements (duplicates allowed)
    ms.insert(5);
    ms.insert(2);
    ms.insert(8);
    ms.insert(2);  // Duplicate
    ms.insert(5);  // Another duplicate
    
    // Display elements (automatically sorted)
    cout << "Multiset elements: ";
    for(int x : ms) {
        cout << x << " ";  // Output: 2 2 5 5 8
    }
    cout << endl;
    
    return 0;
}

/*

.insert( {int} )
.erase( {int} )
.count( {int} ) -> Count occurences
if(ms.find( {int} ) != ms.end() )
.find( {int} ) -> return an iterator

multiset<int, greater<int>> descending_ms; 

// lower_bound: first element >= value
    auto lb = ms.lower_bound(3);
    cout << *lb

// upper_bound: first element > value
    auto ub = ms.upper_bound(3);
    cout << *ub

Insertion, deletion, search: O(log n) time complexity
O(1) access min/max using *ms.begin() OR *ms.rbegin() 
Elements cannot be modified directly (must erase and reinsert)
Implemented as self-balancing BST (usually Red-Black Tree)

Common Use Cases:
    Implementing priority-like behavior with quick access to min/max
    Storing multiple occurrences of the same value while maintaining order

*/