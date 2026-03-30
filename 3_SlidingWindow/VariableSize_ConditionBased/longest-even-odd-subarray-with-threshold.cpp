#include <bits/stdc++.h>
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int n = nums.size();
        int L = 0, R = 0;
        while(L < n){
            if(nums[L] % 2 == 1){ 
                L++; 
                continue; 
            }
            if(nums[L] > threshold){ 
                L++; 
                continue; 
            }
            R = L + 1;
            while(R < n && nums[R] <= threshold && 
                nums[R] % 2 != nums[R - 1] % 2){
                    R++;
                }

            ans = max(ans, R - L);
            L = R;
        }
        return ans;
    }
};