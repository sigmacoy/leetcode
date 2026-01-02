#include <bits/stdc++.h>
// With DP
class Solution {
public:
    int maxResult(vector<int>& A, int k) {
        deque<pair<int, int>> dp;
        dp.emplace_front(A[0], 0);

        for(int i = 1; i < A.size(); i++){
            while(dp.front().second + k < i){
                dp.pop_front();
            }
            int cost = dp.front().first + A[i];
            while(!dp.empty() && cost >= dp.back().first){
                dp.pop_back();
            }
            dp.emplace_back(cost, i);
        }

        return dp.back().first;
    }
};
// time and space: O(n)

/*
Input: nums = [ 1,-1, -2, 4, -7, 3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] 
The sum is 7.
*/