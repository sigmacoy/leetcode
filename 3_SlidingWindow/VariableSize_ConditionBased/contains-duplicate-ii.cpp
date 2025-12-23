#include <bits/stdc++.h>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> windowS;
        int L = 0;
        for(int R = 0; R < nums.size(); R++){
            if(windowS.count(nums[R])) return true;
            windowS.insert(nums[R]);
            if(R - L >= k){
                windowS.erase(nums[L]);
                L++;
            }
        }
        return false;
    }
};
// time: O(n)
// space: O(n)
/*
[1,2,3,1], k = 3
Output: true

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/