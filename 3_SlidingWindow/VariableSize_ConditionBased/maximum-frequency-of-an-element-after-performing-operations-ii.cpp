#include <bits/stdc++.h>
class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations){
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0, cnt = 0;
        int l = 0, r = 0;

        // Consider nums[i]
        for(int i = 0; i < n; i++){
            const int x = nums[i], L = max(1, x - k), R = min(nums.back(), x + k);

            // count freq
            int f = 1;
            int j = i + 1;
            for (; j < n && nums[j] == x; j++){
                f++;
            }

            i = j - 1; // nums[j]!=x

            // move l
            while (l < n && nums[l] < L) l++;

            // move r
            r = (r > i) ? r : i; // start r from last position
            while (r + 1 < n && nums[r + 1] <= R){
                r++;
            }

            cnt = r - l + 1;
            ans = max( ans, f + min(cnt - f, numOperations) );
        }

        // consider the subintervals with overlapping
        for (l = 0, r = 0; r < n; r++) {
            int x = nums[r], L = max(1, x - 2 * k);
            while (l < r && nums[l] < L){
                l++;
            }
            ans = max(ans, min(r - l + 1, numOperations));
        }

        return ans;
    }
};
// time: O(n log n + n + n)
// space: O(1)

/*

Input: nums = [1,4,5], k = 1, numOperations = 2
Output: 2

Explanation:
We can achieve a maximum frequency of two by:
Adding 0 to nums[1], after which nums becomes [1, 4, 5].
Adding -1 to nums[2], after which nums becomes [1, 4, 4].

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= k <= 10^9
0 <= numOperations <= nums.length
*/