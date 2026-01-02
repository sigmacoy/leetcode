#include <bits/stdc++.h>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        unordered_map<char, int> s1_mp, s2_mp;
        for(char ch: s1) s1_mp[ch]++;
        int L = 0;
        for(int R = 0; R < m; R++){
            s2_mp[s2[R]]++;

            if(R - L + 1 > n){
                s2_mp[s2[L]]--;
                if(s2_mp[s2[L]] == 0) s2_mp.erase(s2[L]);
                L++;
            }

            if(R - L + 1 == n){
                if(s1_mp == s2_mp) return true;
            }
        }

        return false;
    }
};
// time: O(n + m)
// space: O(26 + 26)

/*
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/