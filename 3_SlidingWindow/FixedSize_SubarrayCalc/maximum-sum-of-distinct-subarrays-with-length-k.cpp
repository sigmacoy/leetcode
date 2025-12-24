#include <bits/stdc++.h>
class Solution {
public:
    long long maximumSubarraySum(vector<int>& A, int k) {
        unordered_set<int> s;
        long long ans = 0, sum = 0;
        int L = 0, R = 0;

        while(R < A.size()){
            while(s.count(A[R])){
                s.erase(A[L]);
                sum -= A[L];
                L++;
            }
            s.insert(A[R]);
            sum += A[R];
            while(R - L + 1 > k){
                s.erase(A[L]);
                sum -= A[L];
                L++;
            }
            if(R - L + 1 == k){
                ans = max(ans, sum);
            }
            R++;
        }
        return ans;
    }
};
// time:
// O(2n - k) -> n additions og n - k removals
// space:
// O(k) where k is distinct integers

/*
[1,5,4,2,9,9,9] k = 3
Output: 11
*/