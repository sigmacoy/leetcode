#include <bits/stdc++.h>
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> psum(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val = matrix[i][j] + psum[i][j + 1] + psum[i+1][j] - psum[i][j];
                psum[i + 1][j + 1] +=  val;
            }
        }

        // print
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0;j<=m; j++){
        //         cout << psum[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int c = 0;
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < m; c1++) {
                for (int r2 = r1; r2 < n; r2++) {
                    for (int c2 = c1; c2 < m; c2++) {
                        int subSum = psum[r2 + 1][c2 + 1] - psum[r1][c2 + 1] - psum[r2 + 1][c1] + psum[r1][c1];
                        if (subSum == target) c++;
                    }
                }
            }
        }
        return c;
    }
};
/*
Because a rectangle is defined by 4 coordinates:
Top row (r1)
Left column (c1)
Bottom row (r2)
Right column (c2)
*/