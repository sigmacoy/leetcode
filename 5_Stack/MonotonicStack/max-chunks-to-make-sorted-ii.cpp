#include <bits/stdc++.h>

class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int n = A.size();
        stack<int> st;
        for(int num : A){
            int largest = num;
            while(!st.empty() && st.top() > num){
                largest = max(largest, st.top());
                st.pop();
            }
            st.push(largest);
        }

        return st.size();
    }
};