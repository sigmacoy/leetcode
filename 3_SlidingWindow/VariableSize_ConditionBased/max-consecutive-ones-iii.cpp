#include <bits/stdc++.h>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0;
        int z = 0;
        int maxLen = 0;

        for (int R = 0; R < n; R++){
            if (nums[R] == 0) z++;
            while (z > k){
                if (nums[L] == 0){
                    z--;
                }
                L++;  
            }
            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen;
    }
};
// time: O(n)
// space O(1)
/*
Input: nums = [1,1,1,0,0, 0,1,1,1,1,0 ], k = 2
Output: 6
Explanation:  [1,1,1,0,0, 1,1,1,1,1,1 ]
*/