#include <bits/stdc++.h>

// Here is Monotonic Stack Soln
class Solution {
public:
    int trap(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        vector<int> st;
        
        for(int R = 0; R < n; R++){
            while(!st.empty() && A[st.back()] < A[R]){
                int m = st.back();
                st.pop_back();
                if(st.empty()) break; // if flag or mas taas ang behind
                int l = st.back();
                int h = min(A[R] - A[m], A[l] - A[m]);
                int w = R - l - 1;
                ans += h * w;
            }
            st.push_back(R);
        }

        return ans;
    }
};






// 2P solution 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int L = 0, R = n - 1, maxL = 0, maxR = 0;
        int totalWater = 0;
        
        while(L < R){
            if(height[L] < height[R]){
                if(height[L] >= maxL) maxL = height[L];
                else totalWater += maxL - height[L];
                L++;
            } else {
                if(height[R] >= maxR) maxR = height[R];
                else totalWater += maxR - height[R];
                R--;
            }
        }

        return totalWater;
    }
};