#include <bits/stdc++.h>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && A[st.top()] < A[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};

/*
monotonic decreasing stack
ang top sa stack kay ang smallest temperature index

*/
