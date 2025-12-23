#include <bits/stdc++.h>
class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int L = 0, z = 0, ans = 0, n = A.size();
        
        for (int R = 0; R < n; R++){
            if(A[R] == 0) z++;
            
            while (z > 1){
                if (A[L] == 0) z--;
                L++;
            }
            
            ans = max(ans, R - L + 1);
        }
        
        return ans > 0 ? ans - 1 : 0;
    }
};
// time O(n)
// space O(1)
/*
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1]
*/