#include <bits/stdc++.h>
// expand from center pattern
class Solution {
    void expandAroundCenter(string& s, int l, int r, int& start, int& maxLen){
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        // adjust kay nasubra one step, kay maskin pag l == 0, mo minus ra baya gihapon
        l++;
        r--;

        int currLen = r - l + 1;
        if(currLen > maxLen){
            maxLen = currLen;
            start = l;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(!n) return "";
        int start = 0, maxLen = 1;
        for(int i = 0; i < n; i++){
            expandAroundCenter(s, i, i, start, maxLen); // odd length
            expandAroundCenter(s, i, i + 1, start, maxLen); // even length
        }
        return s.substr(start, maxLen); // .substr(inclusive, exclusive)
    }
};
// time: O(n^2) at worst case
// space: O(1)