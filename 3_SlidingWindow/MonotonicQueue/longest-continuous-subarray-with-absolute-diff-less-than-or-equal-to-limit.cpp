#include <bits/stdc++.h>
// Monotonic Queue
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        int n = A.size();
        deque<int> maxd, mind;
        int i = 0, j;
        for(j = 0; j < n; j++){
            while(!maxd.empty() && A[j] > maxd.back())
                maxd.pop_back();
            while(!mind.empty() && A[j] < mind.back())
                mind.pop_back();
            
            maxd.push_back(A[j]);
            mind.push_back(A[j]);

            if(maxd.front() - mind.front() > limit){
                if(maxd.front() == A[i]) maxd.pop_front();
                if(mind.front() == A[i]) mind.pop_front();
                i++;
            }
        }

        return j - i;
    }
};
// time O(n)
// space O(n)

/*
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5
*/