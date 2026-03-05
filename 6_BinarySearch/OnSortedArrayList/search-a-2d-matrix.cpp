#include <bits/stdc++.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), L = 0, R = (m * n) - 1;
        
        while(L <= R){
            int mid = L + (R - L) / 2;
            int midV = matrix[mid / n][mid % n];

            if(midV == target) return true;
            else if(midV < target) L = mid + 1;
            else R = mid - 1;
        }

        return false;
    }
};