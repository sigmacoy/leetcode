#include <bits/stdc++.h>
// expand from center pattern
class Solution {
    int expandAroundCenter(string& s, int l, int r){
        int c = 0;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            c++;
            l--;
            r++;
        }
        return c;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int c = 0;
        for(int i = 0; i < n; i++){
            c += expandAroundCenter(s, i, i); // odd length
            c += expandAroundCenter(s, i, i + 1); // even length
        }
        return c;
    }
};
// time: O(n^2) at worst case
// space: O(1)