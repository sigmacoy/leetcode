#include <bits/stdc++.h>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return (double)nums[0];
        }
        int maxSum = 0;
        for(int i = 0; i < k; i++){
            maxSum += nums[i];
        }
        int l = 0;
        int r = k;
        int cSum = maxSum;
        while(r < n){
            cSum = cSum - nums[l] + nums[r];
            maxSum = max(maxSum, cSum);
            l++; r++;
        }
        return (double) maxSum / k;
    }
};
// time: O(n)
// space: O(1)