#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<char, int> freq = {
        {'a', 2},
        {'b', 1},
        {'c', 0},
        {'d', 5},
        {'e', 1}
    };

    // Step 1: Copy to vector
    vector<pair<char, int>> vec(freq.begin(), freq.end());

    // Step 2: Sort by frequency (ascending)
    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second; // sort by frequency
    });

    // Step 3: Print result
    for (auto & p : vec) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

//

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
    
        for (int num : nums) freq[num]++;
            
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b]; // Ascending frequency
            } else {
                return a > b; // If equal frequency, sort by value descending
            }
        });
    
        return nums;
    }
};

// 