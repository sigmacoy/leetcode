#include <bits/stdc++.h>

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<string> st;
        int currNum = 0;
        string currString = "";
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                currNum = currNum * 10 + (ch - '0');
            } else if(isalpha(ch)){
                currString += ch;
            } else if(ch == '['){
                st.push(currString);
                st.push(to_string(currNum));
                currString = "";
                currNum = 0;
            } else if(ch == ']'){
                int num = stoi(st.top()); st.pop();
                string prevString = st.top(); st.pop();
                string newString = "";
                for(int i = 1; i <= num; i++){
                    newString += currString;
                }
                currString = prevString + newString;
            }
        }

        return currString;
    }
};