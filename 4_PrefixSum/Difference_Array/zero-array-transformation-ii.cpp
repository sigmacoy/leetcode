#include <bits/stdc++.h>
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, pos = 0;
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) {
                
                // if fail to make zero array
                if (pos == queries.size()) return -1;
                
                int start = queries[pos][0];
                int end = queries[pos][1];
                int val = queries[pos][2];
                
                pos++;
                
                if (end < i) continue; // skip past update

                // range update in O(1)
                diff[max(start, i)] += val;
                diff[end + 1] -= val;
            }
            sum += diff[i];
        }

        return pos;
    }
};