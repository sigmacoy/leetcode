#include <bits/stdc++.h>

class Solution {
    int area(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++){
            int h;
            if(i == n) h = 0;
            else h = heights[i];
            while(!st.empty() && h < heights[st.top()]){
                int currH = heights[st.top()];
                st.pop();
                int currW;
                if(st.empty()) currW = i;
                else currW = i - st.top() - 1;
                maxArea = max(maxArea, currH * currW);
            }
            st.push(i);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        if (m == 0) return 0;
        int n = mat[0].size();

        vector<int> hist(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1') hist[j]++;
                else hist[j] = 0;
            }
            ans = max(ans, area(hist));
        }

        return ans;
    }
};
/*
check every row
tallest rectangle ending here?
similar to largest rectangle in histogram but checks per row

time:
    O(n + n + n + n + mn)
space: O(2n), for hist and stack
*/