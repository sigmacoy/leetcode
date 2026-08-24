#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // THIS IS HARD, IDC MEDIUM ANG DIFFICULTY
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> psum(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                psum[i + 1][j + 1] = mat[i][j] + psum[i][j + 1] + psum[i + 1][j] - psum[i][j];
            }
        }

        // print
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0;j<=m; j++){
        //         cout << psum[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k);
                
                ans[i][j] = psum[r2 + 1][c2 + 1] - psum[r1][c2 + 1] - psum[r2 + 1][c1] + psum[r1][c1];
            }
        }
        return ans;
    }
};