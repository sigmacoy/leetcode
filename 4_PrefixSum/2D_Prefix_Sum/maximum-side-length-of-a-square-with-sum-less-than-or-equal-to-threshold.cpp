#include <bits/stdc++.h>
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> psum(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                psum[i + 1][j + 1] = mat[i][j] + psum[i + 1][j] + psum[i][j + 1] - psum[i][j];
            }
        }
        int maxLen = 0;
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < m; c1++) {
                int len = maxLen + 1;
                while (r1 + len - 1 < n && c1 + len - 1 < m) {
                    int r2 = r1 + len - 1;
                    int c2 = c1 + len - 1;
                    int subSum = psum[r2 + 1][c2 + 1] - psum[r1][c2 + 1] - psum[r2 + 1][c1] + psum[r1][c1];
                    
                    if (subSum <= threshold) {
                        maxLen = len;
                        len++;
                    } else break;
                }
            }
        }
        return maxLen;
    }
};