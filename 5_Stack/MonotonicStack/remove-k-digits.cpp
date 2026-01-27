#include <bits/stdc++.h>

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char digit : num){
            // 1 2 1 9
            while(!st.empty() && st.top() > digit && k > 0){
                st.pop();
                k--;
            }
            if(!st.empty() || digit != '0') st.push(digit);
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        string res = "";
        while(!st.empty()){
            res += st.top(); 
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
/*
time O(n + n + n)
space O(n)
*/