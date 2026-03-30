#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int L = 0, R = n - 1;
        while(L < R){
            int mid = L + (R - L) / 2;
            if(nums[mid] > nums[R]){
                L = mid + 1;
            } else R = mid;
        }
        return nums[L];
    }
};