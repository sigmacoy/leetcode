#include <bits/stdc++.h>
class Solution {
public:
    long long maximumSubarraySum(vector<int>& A, int k) {
        int n = A.size();
        long long maxAns = LLONG_MIN;
        unordered_map<int, long long> min_prefix;
        long long currSum = 0;
        
        for (int j = 0; j < n; j++) {
            currSum += A[j];
            
            // Check target1 = A[j] + k
            if (min_prefix.count(A[j] + k)) {
                long long candidate = currSum - min_prefix[A[j] + k];
                if (maxAns == LLONG_MIN || candidate > maxAns) {
                    maxAns = candidate;
                }
            }
            // Check target2 = A[j] - k
            if (min_prefix.count(A[j] - k)) {
                long long candidate = currSum - min_prefix[A[j] - k];
                if (maxAns == LLONG_MIN || candidate > maxAns) {
                    maxAns = candidate;
                }
            }
            
            // Update min_prefix for A[j]
            long long prefix_before_j = currSum - A[j];
            if (!min_prefix.count(A[j]) || prefix_before_j < min_prefix[A[j]]) {
                min_prefix[A[j]] = prefix_before_j;
            }
        }
        
        return maxAns == LLONG_MIN ? 0 : maxAns;
    }
};

/*
Time:
Space:

Input: nums = [1,2,3,4,5,6], k = 1
Output: 11
Explanation: The absolute difference between the first and 
 last element must be 1 for a good subarray. 
All the good subarrays are: [1,2], [2,3], [3,4], [4,5], and [5,6]. 
The maximum subarray sum is 11 for the subarray [5,6].
*/