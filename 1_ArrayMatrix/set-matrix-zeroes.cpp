#include <bits/stdc++.h>

class Solution {
    void help(vector<vector<int>>& matrix, int i, int j, int n, int m){
        for(int x = 0; x < m; x++){
            matrix[i][x] = 0;
        }
        for(int x = 0; x < n; x++){
            matrix[x][j] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> temp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    temp.push_back({i, j});
                }
            }
        }

        for(auto p : temp){
            // cout << p.first <<  " " << p.second << endl;
            help(matrix, p.first, p.second, n, m);
        }
    }
};
// time space complexity:
// O(k × (n + m)) where k = number of zeros
// worst case: O(n²m + nm²) when matrix is all zeros
// space: O(k) where k = number of zeros