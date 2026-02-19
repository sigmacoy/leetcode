#include <bits/stdc++.h>
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int maxW = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty() || nums[st.top()] > nums[i])
                st.push(i);
        }
        // 6 0
        
        for(int i = n - 1; i > 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                maxW = max(maxW, i - st.top());
                st.pop();
            }
        }
        return maxW;
    }
};
/*
5 x 10^4

my time complexity
O(n) + O(n)
O(2n)

space: 
O(n)
*/