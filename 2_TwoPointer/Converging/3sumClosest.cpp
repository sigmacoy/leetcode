#include <bits/stdc++.h>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closeSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int currSum = nums[i] + nums[l] + nums[r];
                if(abs(currSum - target) < abs(closeSum - target)) // it must choose the smaller one
                    closeSum = currSum;
                
                if(currSum < target){
                    l++;
                } else if(currSum > target) r--;
                else return currSum;
            }
        }

        return closeSum;
    }
};

/*
time O(n log n + n * n)
space O(log n)

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/