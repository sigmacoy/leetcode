#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> uSet;
        int l = 0, r = 0;
        int maxLen = 0;
        while(r < n){
            if(uSet.count(s[r])){
                uSet.erase(s[l]);
                l++;
            } else {
                uSet.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
        }
        return maxLen;
    }
};
// time O(n)
// space O(n)
/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
*/