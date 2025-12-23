#include <bits/stdc++.h>
class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int n = A.size();
        int sum = 0;
        
        for(int num : A) sum += num;
        
        int target = sum - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        
        int L = 0, currSum = 0, maxLen = -1;
        for(int R = 0; R < n; R++) {
            currSum += A[R];
            
            while(currSum > target && L <= R) {
                currSum -= A[L];
                L++;
            }
            
            if(currSum == target) {
                maxLen = max(maxLen, R - L + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};

/*
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
*/