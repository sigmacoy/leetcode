#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> ans;
        sort(A.begin(), A.end());

        for(int i = 0; i < n; i++){
            int a = A[i];
            if(a > 0) break;
            if(i != 0 && a == A[i - 1]) continue;

            int L = i + 1, R = n - 1;
            while(L < R){
                int sum = a + A[L] + A[R];
                if(sum == 0){
                    ans.push_back({a, A[L], A[R]});
                    L++;
                    R--;
                    while(L < R && A[L] == A[L - 1]) L++;
                } else if(sum > 0) R--;
                else L++;
            }
        }

        return ans;
    }
};
/*
time O(n^2)
space O(n)
*/