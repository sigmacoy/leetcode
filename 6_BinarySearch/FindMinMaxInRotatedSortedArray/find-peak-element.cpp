#include <bits/stdc++.h>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0, R = nums.size() - 1;
        while(L < R){
            int mid = L + (R - L) / 2;
            if(nums[mid] > nums[mid + 1]){
                R = mid;
            } else L = mid + 1; // way labot mid value
        }

        return L; 
    }
};