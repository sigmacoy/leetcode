#include <bits/stdc++.h>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        unordered_map<char, int> s_mp, p_mp;
        for(char ch : p) p_mp[ch]++;
        int L = 0;
        for(int R = 0; R < n; R++){
            s_mp[s[R]]++;

            if(R - L + 1 > m){
                s_mp[s[L]]--;
                if(s_mp[s[L]] == 0) s_mp.erase(s[L]);
                L++;
            }

            if(R - L + 1 == m){
                if(s_mp == p_mp){
                    ans.push_back(L);
                }
            }
        }
        return ans;
    }
};
// time O(n + m)
// space O(26 + 26)

/*
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/