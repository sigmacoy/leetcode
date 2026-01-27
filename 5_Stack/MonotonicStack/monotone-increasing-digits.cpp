#include <bits/stdc++.h>
// greedy soln

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int len = s.size();
        
        // pangita first violation left to right
        int mark = len;
        for(int i = len - 1; i > 0; i--){
            if(s[i] < s[i - 1]){
                mark = i;
                s[i - 1]--;
            }
        }
        
        for(int i = mark; i < len; i++){
            s[i] = '9';
        }
        
        return stoi(s);
    }
};