#include <bits/stdc++.h>
class Solution {
public:
    int maxFrequency(vector<int>& A, int k, int numO) {
        int mxPossible = *max_element(A.begin(), A.end());
        vector<int> freq(mxPossible + 2, 0), diff(mxPossible + 2, 0);
        
        for(auto& num : A){
            freq[num]++;
            diff[ max(0, num - k) ]++;
            diff[ min(mxPossible, num + k) + 1 ]--;
        }

        int mxFreq = 0, currFreq = 0;
        for(int i = 0; i <= mxPossible; i++){
            currFreq += diff[i];
            int finalOp = currFreq - freq[i];

            int canChange = min(finalOp, numO);
            int freqPossible = freq[i] + canChange;
            mxFreq = max(mxFreq, freqPossible);
        }
        
        return mxFreq;
    }
};
/*
time: O(n + maxVal)
space: O(maxVal)

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