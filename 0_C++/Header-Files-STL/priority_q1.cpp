#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std; 

int findMinUsingPriorityQueue(const vector<int>& nums) {
    if (nums.empty()) {
        return INT_MAX; 
    }

    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    return minHeap.top();
}

int findMaxUsingPriorityQueue(const vector<int>& nums) {
    if (nums.empty()) {
        return INT_MIN; 
    }

    priority_queue<int> maxHeap(nums.begin(), nums.end()); 
    return maxHeap.top();
}

int main() {
    vector<int> numbers = {5, 2, 9, 1, 5, 6};

    int minVal = findMinUsingPriorityQueue(numbers);
    int maxVal = findMaxUsingPriorityQueue(numbers);

    cout << "Minimum element: " << minVal << endl;
    cout << "Maximum element: " << maxVal << endl;

    return 0;
}


    // #include <iostream>
    // #include <queue>
    // #include <vector>

    // int main() {
    //     // Min-Heap Priority Queue
    //     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Sorted Increasing

    //     // Insert elements
    //     minHeap.push(10);
    //     minHeap.push(5);
    //     minHeap.push(15);
    //     minHeap.push(1);

    //     // Removing elements (smallest first)
    //     while (!minHeap.empty()) {
    //         std::cout << minHeap.top() << " "; // Output: 1 5 10 15
    //         minHeap.pop();
    //     }

    //     return 0;
    // }


// POP
    // priority_queue<int> maxPQ; // Max-Heap (Default)
    // priority_queue<int, vector<int>, greater<int>> minPQ; // Min-Heap

    // maxPQ.push(10);
    // maxPQ.push(20);
    // maxPQ.push(5);

    // minPQ.push(10);
    // minPQ.push(20);
    // minPQ.push(5);

    // cout << "Max-Heap pop: " << maxPQ.top() << endl; // 20 (rightmost in sorted order)
    // maxPQ.pop();

    // cout << "Min-Heap pop: " << minPQ.top() << endl; // 5 (leftmost in sorted order)
    // minPQ.pop();

