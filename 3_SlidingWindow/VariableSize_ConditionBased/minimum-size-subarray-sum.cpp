#include <bits/stdc++.h>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int L = 0;
        int minLen = INT_MAX;
        int sum = 0;
        for(int R = 0; R < n; R++){
            sum += nums[R];
            while(sum >= target){
                int len = R - L + 1;
                minLen = min(minLen, len);
                sum -= nums[L];
                L++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
// time: O(n)
// space: O(1)
// EASY

/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/