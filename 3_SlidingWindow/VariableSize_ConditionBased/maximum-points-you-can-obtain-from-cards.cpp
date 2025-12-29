#include <bits/stdc++.h>
class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int n = A.size();
        int ans = 0;
        int L = 0, R = n - 1 - k;
        int sum = 0;
        for(int i = R + 1; i < n; i++){
            sum += A[i];
        }
        ans = sum;
        R = n - k;
        while(R < n){
            sum += A[L];
            sum -= A[R];
            ans = max(ans, sum);
            L++;
            R++;
        }
        return ans;
    }
};
/*
time:
    O(k) + O(k)
    O(2k)

space:
    O(1)

[100,40,17,9,73,75], k = 3
Output: 248
*/