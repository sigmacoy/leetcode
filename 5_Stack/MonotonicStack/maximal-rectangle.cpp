#include <bits/stdc++.h>

// MONOTONIC non-decreasing (strictly less than)

class Solution {
    int area(vector<int>& heights){ // hist
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++){
            int h = (i == n) ? 0 : heights[i];
            while(!st.empty() && h < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();

        vector<int> hist(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') hist[j]++;
                else hist[j] = 0;
            }
            ans = max(ans, area(hist));
        }

        return ans;
    }
};
/*
1 0 1 0 0
2 0 2 1 1
3 1 3 2 2
4 0 0 3 0


check every row
tallest rectangle ending here?
similar to largest rectangle in histogram but checks per row

time:
    O(n + n + n + n + mn)
space: O(2n), for hist and stack
*/