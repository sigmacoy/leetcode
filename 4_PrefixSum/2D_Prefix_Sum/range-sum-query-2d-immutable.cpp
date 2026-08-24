#include <bits/stdc++.h>
class NumMatrix {
    vector<vector<int>> psum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        psum.assign(n + 1, vector<int>(m + 1, 0));
        int runSum = 0;
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
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return psum[row2 + 1][col2 + 1] - psum[row2 + 1][col1] - psum[row1][col2 + 1] + psum[row1][col1];
    }
};

/**
Time taken: 32m 39s
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 * 
 * 
 * Left, Down, then to the right...
 */
