#include <bits/stdc++.h>
// In a proper O(n) sliding window, R only moves forward and never resets.
// Monotonic Queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int R = 0; R < n; R++){
            // remove elements outside of window
            if(!dq.empty() && dq.front() <= R - k){
                dq.pop_front();
            }
            // remove from the back of dq nga smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[R]){
                dq.pop_back();
            }

            dq.push_back(R);

            if(R >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
// time O(n)
// space O(k) or O(n) at worst case

/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

// MULTISET APPROACH SOLUTION
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        multiset<int> ms;
        vector<int> ans;
        for(int i = 0; i < A.size(); i++){
            ms.insert(A[i]);
            if(i >= k){
                ms.erase(ms.find(A[i - k]));
            }
            if(i >= k - 1){
                ans.push_back(*ms.rbegin());
            }
        }

        return ans;
    }
};