#include <bits/stdc++.h>
// expand from center pattern
class Solution {
    int expandAroundCenter(string& s, int l, int r, int n){
        int c = 0;
        while(l >= 0 && r < n){
            if(s[l] != s[r]) break;
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
            c += expandAroundCenter(s, i, i, n); // odd length
            c += expandAroundCenter(s, i, i + 1, n); // even length
        }
        return c;
    }
};
// time: O(n^2) at worst case
// space: O(1)

/*
if s == "aaaa"
i=0: odd expands 4 times, even expands 3 times → 7
i=1: odd expands 3 times, even expands 2 times → 5
i=2: odd expands 2 times, even expands 1 time → 3
i=3: odd expands 1 time, even expands 0 times → 1
Total = 7+5+3+1 = 16 = n² = 4²
*/