#include <bits/stdc++.h>
class Solution {
public:
    long long continuousSubarrays(vector<int>& A) {
        long long c = 0;
        int L = 0;
        int n = A.size();

        multiset<int> ms;
        for(int R = 0; R < n; R++){
            ms.insert(A[R]);
            while(*ms.rbegin() - *ms.begin() > 2){
                ms.erase( ms.find( A[L] ) );
                L++;
            }
            c += R - L + 1;
        }

        return c;
    }
};
/* 
  L
5 4 2 4
      R

ms = 4, 4, 5
c = 1 + 2 + 2 + 3
c = 8

*/
 
/*
time: O(n)
space: O(n)

Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
*/