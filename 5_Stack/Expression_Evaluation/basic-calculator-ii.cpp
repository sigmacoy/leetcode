#include <bits/stdc++.h>

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        char op = '+';
        int currNum = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                currNum = currNum * 10 + (ch - '0');
            }
            if(ch == ' ' && i != n - 1) continue;
            if(!isdigit(ch) || i == n - 1){ // or at the end
                if(op == '+'){
                    st.push(currNum);
                } else if(op == '-'){
                    st.push(-currNum);
                } else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * currNum);
                } else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / currNum);
                }

                op = ch;
                currNum = 0;
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        return ans;
    }
};
/*
Input: s = "3+2*2"
Output: 7
*/