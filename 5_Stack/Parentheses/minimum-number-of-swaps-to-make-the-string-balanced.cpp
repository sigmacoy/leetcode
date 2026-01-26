#include <bits/stdc++.h>

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        
        for(char &ch : s) {
            if(ch == '[') st.push(ch);
            else if( !st.empty() ) st.pop();
        }       
        return (st.size() + 1) / 2;
    }
};
// time and space O(n) 

// class Solution {
// public:
//     int minSwaps(string s) {
//         int n = s.length();
//         int c = 0;
//         for(int i = 0; i < n; i++){
//             if(s[i] == '[') c++;
//             else if(c > 0) c--;
//         }

//         return (c + 1) / 2;
//     }
// };
// time O(n) space O(1)