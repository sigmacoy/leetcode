#include <bits/stdc++.h>
// Segment Tree
class NumArray {
public:
    NumArray(vector<int>& nums) {
        
    }
    
    void update(int index, int val) {
        
    }
    
    int sumRange(int left, int right) {
        
    }
};

// Brute force solution but fails due to: 1 <= nums.length <= 3 * 1e4
// At most 3 * 1e4 calls will be made to update and sumRange.
class NumArray {
    vector<int> prefix;
    vector<int> origNums;
public:
    NumArray(vector<int>& nums) {
        origNums = nums;
        buildPrefix();
    }

    void buildPrefix(){
        int n = origNums.size();
        prefix.assign(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + origNums[i];
        }
    }
    
    void update(int index, int val) {
        origNums[index] = val;
        buildPrefix();
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
// time O(n + n + 1)
// space O(n)