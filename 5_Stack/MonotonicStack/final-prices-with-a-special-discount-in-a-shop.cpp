#include <bits/stdc++.h> // EASY PROBLEM
class Solution {
public:
    vector<int> finalPrices(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && A[st.top()] >= A[i]){
                A[st.top()] -= A[i];
                st.pop();
            }
            st.push(i);
        }
        return A;
    }
};
/*
8 4 6 2 3
4 2 3 2 3
time: O(2n)
space: O(1) kay gi modify in-place
*/