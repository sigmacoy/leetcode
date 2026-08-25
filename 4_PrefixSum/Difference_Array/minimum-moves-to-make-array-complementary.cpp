#include <bits/stdc++.h>
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size(); // even
        vector<int> diff(2 * limit + 2, 0);
        for(int i = 0; i<n/2;i++){
            int a=min(nums[i], nums[n - i - 1]);
            int b=max(nums[i], nums[n - i - 1]);
            diff[2] += 2;
            diff[a + 1] -= 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] += 1;
        }
        int minOps = n, currOps = 0;
        for(int c = 2; c <= 2 * limit; c++){
            currOps += diff[c];
            minOps = min(minOps, currOps);
        }
        return minOps;
    }
};