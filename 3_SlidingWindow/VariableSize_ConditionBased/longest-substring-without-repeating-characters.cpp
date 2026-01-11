#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;
        int maxLen = 0;
        int L = 0, R = 0;
        while(R < n){
            while(st.count(s[R])){
                st.erase(s[L]);
                L++;
            }
            st.insert(s[R]);
            maxLen = max(maxLen, R - L + 1);
            R++;
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