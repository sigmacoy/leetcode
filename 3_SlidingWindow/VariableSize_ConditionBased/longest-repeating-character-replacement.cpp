#include <bits/stdc++.h>
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int L = 0;
        int maxFreq = 0;
        int maxLen = 0;
        for(int R = 0; R < n; R++){
            freq[s[R] - 'A']++;
            maxFreq = max(maxFreq, freq[s[R] - 'A']);
            while((R - L + 1) - maxFreq > k){
                freq[s[L] - 'A']--;
                L++;
            }
            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen;
    }
};
// time O(n)
// space O(26)
/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/