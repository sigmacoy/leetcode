#include <bits/stdc++.h>
class Solution {
public:
    string help(string s){
        stack<char> st;
        for (char c : s){
            if (c == '#'){
                if (!st.empty()) st.pop(); 
            } else st.push(c);
        }

        string res = "";
        while (!st.empty()){
            res += st.top(); st.pop();
        }
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return help(s) == help(t);
    }
};
// time O(n)
// space O(n) -> stack

// ab#e 
// ac#e 
// True