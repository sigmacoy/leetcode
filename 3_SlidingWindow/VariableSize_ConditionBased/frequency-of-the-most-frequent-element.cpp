#include <bits/stdc++.h>
class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int L = 0;
        long maxLen = 0, total = 0;

        for(int R = 0; R < A.size(); R++){
            total += A[R];

            while (A[R] * static_cast<long>(R - L + 1) > total + k){
                total -= A[L];
                L++;
            }

            maxLen = max(maxLen, static_cast<long>(R - L + 1));
        }

        return static_cast<int>(maxLen);        
    }
};
// time: sorting is O(n log n) + sliding window O(n)
// = O(n log n + n)
// space O(1)
/*
[1, 1,1,2,2, 4], k = 2
Answer: 4
*/