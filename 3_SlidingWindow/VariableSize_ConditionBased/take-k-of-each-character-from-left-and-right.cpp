#include <bits/stdc++.h>
class Solution {
public:
    int takeCharacters(string s, int k) {
        int charCount[3] = {0};
        int n = s.length();

        for(int i = 0; i < n; i++){
            charCount[ s[i] - 'a' ]++;
        }

        for(int count : charCount){
            if(count < k){
                return -1;
                // if naay character less than k ang count
            }
        }

        int maxWindowSize = 0;
        int L = 0;
        for(int R = 0; R < n; R++){
            int charIndex = s[R] - 'a';
            charCount[charIndex]--;

            while(charCount[charIndex] < k){
                charCount[ s[L] - 'a' ]++;
                L++;
            }

            maxWindowSize = max(maxWindowSize, R - L + 1);
        }
        return n - maxWindowSize;
    }
};
// time: O(n) sliding window
// space: O(n)

/*
Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
*/