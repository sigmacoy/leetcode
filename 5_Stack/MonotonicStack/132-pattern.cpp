#include <bits/stdc++.h>
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        vector<int> min_left(n);
        min_left[0] = nums[0];

        for(int i = 1; i < n; i++){
            min_left[i] = min(min_left[i - 1], nums[i]);
        }

        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > min_left[i]){
                while(!st.empty() && st.top() <= min_left[i]){
                    st.pop();
                }
                if(!st.empty() && st.top() < nums[i]){
                    return true;
                }

                st.push(nums[i]);
            }
        }

        return false;
    }
};