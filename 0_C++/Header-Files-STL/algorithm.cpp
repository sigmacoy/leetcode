// Types of Algorithm: Sorting, Recursive, Backtracking, Greedy, Randomized, Divide & Conquer, Dynamic Programming

// find(v.begin(), v.end(), val); ==> If the value is found in the range, returns an iterator to its position.
//                             If the value is not found, returns an iterator to the end of the range.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> data = {9,8,7,6,5,4,3,2};

    auto itfound = find(data.begin(), data.end(), 6);

    if (itfound == data.end()) cout << "6 not found in range" << endl;
    else {
        cout << *itfound << endl;
        cout << "Index: " << itfound - data.begin() << endl;
    }
}

// if( find(v.begin(), v.end(), val) != v.end() )


// sort(v.begin(), v.end()): Sort elements.
    // greater<int>() -> sort descendingly

// reverse(v.begin(), v.end()): Reverse order.
// max(a, b), min(a, b): Get max/min.
// max({a, b, c})
// swap(a, b): Swap values.
// binary_search(v.begin(), v.end(), x): Binary search.
// next_permutation(v.begin(), v.end()): Get next lexicographical permutation.

// int s = *min_element(nums.begin(), nums.end());
// int h = *max_element(nums.begin(), nums.end());

// is_sorted(v.begin(), v.end()); --> return boolean value.

// int counts = count(v.begin(), v.end(), target val);
    // mySet.count(nums[i]) -> return 0 or 1

    // Set Operations == > Requires both vectors to be sorted. and works for vector, set, deque
    // vector<string> result;
    // set_intersection
    // set_union
    // set_symmetric_difference == > Finds elements that are in one set but not both.
    // set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));
    // includes == > return boolean value, if the first set is a subset of the second set.

// remove(begin, end, target); --------------------------------------------------------------------
    // string s = "abBAcC";
    // s.erase(remove(s.begin(), s.end(), 'b'), s.end());
    // Output: "aBAcC"
    
// unique(): Removes consecutive duplicate elements from a sorted or unsorted range but does not actually resize the container. 
    // It just rearranges the elements and returns an iterator to the new end of the unique elements.

// unique(.begin, .end);
    // vector<int> v = {1, 1, 2, 2, 3, 1, 1};

    // auto it = unique(v.begin(), v.end());

    // Print the unique part only
    // for (auto i = v.begin(); i != it; ++i)
    //     cout << *i << " ";
    // }
    // Output:
    // 1 2 3 1

    // Only consecutive duplicates are removed.
    // The vector becomes: {1, 2, 3, 1, ?, ?, ?} (the rest is garbage).
    // The returned iterator points after the last unique element: 1 2 3 1.

// stable_sort()

// all_of --> built-in function that checks if every element matches a condition.
// any_of
// none_of

// lower_bound(.begin(), .end(), val);
// higher_bound() 
// nums = {1, 2, 3, 4, 5, 6};
// lower_bound of 5 is 5.
// Tho index of 5 is 4

    // COUNT how many elements before
    // int count = nums.end() - lower_bound(nums.begin(), nums.end(), x); 
        // Find if a number exists
        // Find where a number can be inserted to keep an array sorted
        // Count elements ≥ a value

// next_permutation(v.begin(), v.end());
// prev_permutation(v.begin(), v.end());

// Modular Arithmetic
    // for (char c : concat) {
    //     mod = (mod * 10 + (c - '0')) % k; 
    // }