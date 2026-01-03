#include <bits/stdc++.h>
class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<int> ans;
        int i = 0, j = 0;

        while(i < n && j < m){
            if(A[i] < B[j]) i++;
            else if(A[i] > B[j]) j++;
            else {
                if(ans.empty() || ans.back() != A[i]){
                    ans.push_back(A[i]);
                }
                i++;
                j++;
            }
        }

        return ans;
    }
};
/*
time (n log n + m log m + n + m)
space O( log( max(n, m) ) + min(n, m))
*/

/*
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/
