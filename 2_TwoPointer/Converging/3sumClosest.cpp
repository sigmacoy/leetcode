
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
                int cSum = nums[i] + nums[l] + nums[r];
                if(abs(cSum - target) < abs(closeSum - target))
                    closeSum = cSum;
                
                if(cSum < target){
                    l++;
                } else if(cSum > target) r--;
                else return cSum;
            }
        }

        return closeSum;
    }
};