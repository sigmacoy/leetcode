#include <bits/stdc++.h>

class Solution {
public:
    long long calculate(string s) {
        int n = s.length();
        stack<long long> st;
        long long currNum = 0;
        long long res = 0;
        int sign = 1;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                currNum = currNum * 10 + (ch - '0');
            } else if(ch == '+' || ch == '-'){
                res += sign * currNum;
                currNum = 0;
                sign = (ch == '+') ? 1 : -1;
            } else if(ch == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if(ch == ')'){
                res += sign * currNum;
                currNum = 0;
                long long prevSign = st.top(); st.pop();
                long long prevRes = st.top(); st.pop();
                res = prevSign * res + prevRes;
            }
        }

        return res + sign * currNum;
    }
};


// memory limit error kay daghan recursion stack calls at worst case
// class Solution {
//     int i = 0;
// public:
//     long long calculate(string s) {
//         int n = s.length();
//         stack<long long> st;
//         char op = '+';
//         long long currNum = 0;

//         while(i < n){
//             char ch = s[i++];
//             if(isdigit(ch)){
//                 currNum = (long long) currNum * 10 + (ch - '0');
//             }

//             if(ch == '(') currNum = calculate(s);

//             if(i == n || 
//                 ch == '+' ||
//                 ch == '-' ||
//                 ch == ')' ){ 

//                 if(op == '+'){
//                     st.push(currNum);
//                 } else if(op == '-'){
//                     st.push(-currNum);
//                 }
//                 op = ch;
//                 currNum = 0;
//             }

//             if(ch == ')') break;
//         }

//         long long ans = 0;
//         while(!st.empty()){
//             ans += (long long) st.top(); st.pop();
//         }
//         return ans;
//     }
// };
/*
"(1+(4+5+2)-3)+(6+8)" -> 23
  1+   11  -3
        9      +  14
            = 23
*/