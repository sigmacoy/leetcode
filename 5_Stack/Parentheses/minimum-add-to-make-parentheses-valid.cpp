#include <bits/stdc++.h>
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        st.push(s[0]);

        for(int i = 1; i < n; i++){
            char ch = s[i];
            if(ch == ')' && !st.empty() && st.top() == '('){
                st.pop();
                continue;
            } 
            st.push(ch);
        }
        
        return st.size();
    }
};