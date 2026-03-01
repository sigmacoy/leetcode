#include <bits/stdc++.h>

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> st;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/')){
            if(part == "" || part == ".") continue;
            if(part == ".."){
                if(!st.empty()) st.pop();
            } else {
                st.push(part);
            }
        }
        if(st.empty()) return "/";
        int sz = st.size() - 1;
        vector<string> vAns(sz + 1);
        while(!st.empty()){
            vAns[sz] = st.top();
            st.pop();
            sz--;
        }
        string ans = "";
        for(string& str : vAns){
            ans += "/" + str;
        }      
        
        return ans;
    }
};

// class Solution {
// public:
//     string simplifyPath(string path) {
//         int n = path.length();
//         stack<string> s;
//         string currStr = "";
//         for(int i = 1; i < n; i++){
//             while(i < n && path[i] != '/' && path[i] != ' '){
//                 currStr += path[i];
//                 i++;
//             }
//             if(currStr.empty()) continue;
//             if(currStr == ".."){
//                 if(!s.empty()){
//                     s.pop();
//                 }
//                 currStr = "";
//                 continue;
//             } else if(currStr == "."){
//                 currStr = "";
//                 continue;
//             }
//             s.push(currStr);
//             currStr = "";
//         }

//         stack<string> temp;
//         while(!s.empty()){
//             temp.push(s.top());
//             s.pop();
//         }

//         s = temp;
//         string ans = "";
//         while(!s.empty()){
//             ans += '/';
//             ans += s.top(); s.pop();
//         }
//         if(ans.empty()) ans = "/";
//         return ans;
//     }
// };
/*

trailing slash should be removed

. -> current
.. -> parent

// -> single slash
/// -> single slash

... -> valid directory or filename
.... -> valid directory or filename
*/