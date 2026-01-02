#include <bits/stdc++.h>
// With Prefix Sum
class Solution {
public:
    int shortestSubarray(vector<int>& A, int k) {
        int ans = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> dq;  // (prefix_sum, end_idx)
        
        for (int R = 0; R < A.size(); R++) {
            curSum += A[R];
            
            if (curSum >= k) {
                ans = min(ans, R + 1);
            }
            // Find the minimum valid window ending at R
            while (!dq.empty() && curSum - dq.front().first >= k) {
                auto [prefix, endIdx] = dq.front();
                dq.pop_front();
                ans = min(ans, R - endIdx);
            }
            // Validate the monotonic deque
            while (!dq.empty() && dq.back().first > curSum) {
                dq.pop_back();
            }
            dq.push_back({curSum, R});
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
time: O(n)
space: O(n)

Input: nums = [1,1,1,1,2,2], k = 4
Output: 3
*/