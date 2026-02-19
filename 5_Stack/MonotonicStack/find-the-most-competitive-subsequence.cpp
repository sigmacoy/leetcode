#include <bits/stdc++.h>
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> st;
        for(int i = 0; i < A.size(); i++){
            while(!st.empty() && st.back() > A[i] &&
                st.size() - 1 + A.size() - i >= k){
                    st.pop_back();
                }
            if(st.size() < k) st.push_back(A[i]);
        }
        return st;
    }
};
/*
monotonic increasing stack

ensures akong pag pop dili ma lapas k

kung ako e pop ning element, 
naa paba koy remaining numbers sa array 
para ma fill ang stack to size k?

2 pop 3 3 pop 4 false false
*/