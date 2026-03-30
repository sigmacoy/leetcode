#include <bits/stdc++.h>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n - 1;

        while(L <= R){
            int mid = L + (R - L) / 2;
            if(nums[mid] == target) return true;
            
            if(nums[L] == nums[mid]){
                L++;
                continue;
            }

            if(nums[L] <= nums[mid]){
                if(nums[L] <= target && target < nums[mid]){
                    R = mid - 1;
                } else L = mid + 1;
            } else {
                if(nums[mid] < target && target <= nums[R]){
                    L = mid + 1;
                } else R = mid - 1;
            }
        }

        return false;
    }
};
/*
worst case example is:
nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
target = 2 (not in array)

0 to n - 1 inclusive
*/