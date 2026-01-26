#include <bits/stdc++.h>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        vector<bool> toRemove(n, false);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i); // push index
            } else if(s[i] == ')'){ 
                if(!st.empty()){ // kung di empty
                    st.pop();
                } else { // kung empty
                    toRemove[i] = true;
                }
            }
        }

        while(!st.empty()){ 
            toRemove[ st.top() ] = true;
            st.pop();
        }
        // above kay assurance for extra '('

        string res = "";
        for(int i = 0; i < n; i++){
            if(!toRemove[i]){
                res += s[i];
            }
        }

        return res;
    }
};
// O(n) time and space