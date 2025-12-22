#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> uSet;
        int l = 0, r = 0;
        int maxLen = 0;
        while(l < n && r < n){
            if(uSet.count(s[r])){
                uSet.erase(s[l]);
                l++;
            } else {
                uSet.insert(s[r]);
                r++;
                maxLen = max(maxLen, r - l);
            }
        }
        return maxLen;
    }
};
// time O(n)
// space O(n)