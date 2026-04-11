#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

vector<vector<int>> matrix(n, vector<int>(m, 0));

// vector<vector<int>> matrix(n);

// for (auto& row : matrix) {
//     row.resize(m);
//     fill(row.begin(), row.end(), 0);
// }

// FIND -> #include <algorithm> // Required for std::find
    // if(find(vec.begin(), vec.end(), val) != vec.end())

// HEAP, uses <vector> but do include <algorithm>
int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9};

    // 1. make_heap: Converts the range into a max-heap (largest element at the front).
    make_heap(v.begin(), v.end());
    // v is now a max-heap: {9, 5, 4, 1, 1, 3} (order can vary)
    cout << "1. Heapified: " << v.front() << " is the max element.\n"; // 9


    // 2. push_heap: Adds a new element (must be at the end) to the heap.
    v.push_back(8); // Add new element to the vector end
    push_heap(v.begin(), v.end()); 
    // The new max element, 9, is now at the front
    cout << "2. Pushed 8: New max element is " << v.front() << ".\n"; //  9

    // 3. pop_heap: Moves the largest element (root) to the end of the range.
    pop_heap(v.begin(), v.end());
    // The largest element is now at v.back()
    int max_val = v.back(); 
    v.pop_back(); // Remove the largest element from the container
    // v is now a heap again, minus the largest element
    cout << "3. Popped max: " << max_val << " was removed. New max is " << v.front() << ".\n"; // 8

    // 4. sort_heap: Turns the entire heap into a sorted range (ascending order).
    sort_heap(v.begin(), v.end());
    // v is now completely sorted: {1, 1, 3, 4, 5, 8}
    cout << "4. Sorted: Container is fully sorted.\n"; 

    return 0;
}