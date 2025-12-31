#include <bits/stdc++.h>
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int N = 1e5 + 1;
        vector<int> freq(N, 0);
        int MM = 0;
        for(int x: nums){
            freq[x]++;
            MM = max(MM, x);
        }
        vector<int> prefix(MM + 1);
        partial_sum(freq.begin(), freq.begin() + MM + 1, prefix.begin());

        int ans = 0, cnt = 0;
        for (int x = 1; x <= MM; x++){
            int L = max(1, x - k), R = min(MM, x + k);
            cnt = prefix[R] - prefix[L - 1];
            ans = max(ans, freq[x] + min(cnt - freq[x], numOperations) );
        }
        
        return ans;
    }
};
// time: O(n + M)
// space: O(M)

/*
Input: nums = [1,4,5], k = 1, numOperations = 2
Output: 2

Explanation:
We can achieve a maximum frequency of two by:
Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
0 <= k <= 10^5
0 <= numOperations <= nums.length
*/