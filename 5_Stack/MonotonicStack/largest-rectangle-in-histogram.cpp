#include <bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size();
        int maxArea = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || A[st.top()] > A[i])){
                int h = A[st.top()];
                st.pop();
                int w;
                if(st.empty()){
                    w = i;
                } else w = i - st.top() - 1; // this st.top() is so peak
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};
/*
e store indices with increasing heights
*/