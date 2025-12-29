#include <bits/stdc++.h>
class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int ans = -1;
        for(char ch = 'a'; ch <= 'z'; ch++){
            for(int len = 1; len <= n; len++){
                int c = 0;
                int L = 0;
                for(int R = 0; R < n; R++){
                    if(s[R] != ch){
                        L = R + 1;
                    }
                    if(R - L + 1 >= len){
                        c++;
                        L++;
                    }
                }
                if(c >= 3){
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
// time: O(26 * n^2) = O(n^2)
// space: O(1)
/*
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.
*/