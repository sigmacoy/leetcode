#include <bits/stdc++.h>

// LHS-min and RHS-min
// MONOTONIC STACK

class Solution {
    vector<int> leftSide(vector<int> &A){
        int n = A.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && A[s.top()] >= A[i]){
                s.pop();
            }
            res[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return res;
    }

    vector<int> rightSide(vector<int> &A){
        int n = A.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && A[s.top()] >= A[i]){
                s.pop();
            }
            res[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        vector<int> leftMin = leftSide(A);
        vector<int> rightMin = rightSide(A);

        for(int i = 0; i < n; i++){
            int width = rightMin[i] - leftMin[i] - 1;
            ans = max(ans, A[i] * width);
        }

        return ans;
    }
};