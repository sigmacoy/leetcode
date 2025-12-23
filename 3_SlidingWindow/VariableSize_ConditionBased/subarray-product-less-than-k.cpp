#include <bits/stdc++.h>
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        
        int c = 0;
        int prod = 1;
        int L = 0;
        for(int R = 0; R < n; R++){
            prod *= nums[R];
            while(prod >= k){
                prod /= nums[L];
                L++;
            }
            c += (R - L + 1);
        }
        return c;   
    }
};
// time: O(n)
// space O(1)