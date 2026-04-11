// NOTES:
// 0. priority_queue is a container adaptor that provides constant time lookup of the
//      largest OR smallest element. (VERY IMPORTANT)
// 1. By default vector is the container used inside.
// 2. Cost of insertion and extraction is logarithmic.
// 3. priority_queue is implemented using make_heap(), push_heap(), pop_heap() functions.

// PROGRAM
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template<typename T> void print_queue(T& q){
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  cout << '\n';
}

int main(){
    // q = Max heap (largest element on top)
    //      uses less<int> by default (descending)
    priority_queue<int> q; 
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}){ 
        q.push(elm); 
    }

    print_queue(q);

    // q2 = Min heap (smallest element on top)
    //      explicitly uses greater<int> (ascending)
    priority_queue<int, vector<int>, greater<int>> q2; 
    for (int elm : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2}) { q2.push(elm); }
    print_queue(q2);

    return 0;
}

// greater -> descending (DEFAULT)
// less -> ascending
// pq in cpp -> maxHeap

/* SYNTAXES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// .push(val) - Adds an element to the priority queue. The queue is then automatically reordered.
// Time Complexity: O(log n)

// .pop() - Removes the top element (the one with the highest priority in a max-heap) from the priority queue. The queue is reordered.
// Note: Calling .pop() on an empty queue is undefined behavior.
// Time Complexity: O(log n)

// .top() - Returns a constant reference to the top element (the element with the highest priority).
// Note: Calling .top() on an empty queue is undefined behavior.
// Time Complexity: O(1)

// .empty() - Returns true if the priority queue is empty, false otherwise.
// Time Complexity: O(1)

// .size() -
// Returns the number of elements in the priority queue.
// Time Complexity: O(1)

// .emplace(args...) -
// Constructs a new element in-place at the end and then reorders the queue. More efficient than .push() for complex objects as it avoids a copy/move operation.
// Time Complexity: O(log n)

*/

/*

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<T>
> class priority_queue;

*/

/*

struct MyCompare {
    bool operator()(const MyObject& a, const MyObject& b) const {
        // Define your custom comparison logic here.
        // Return true if 'a' has *lower* priority than 'b'.
        return a.some_value < b.some_value;
    }
};
std::priority_queue<MyObject, std::vector<MyObject>, MyCompare> custom_pq;

*/