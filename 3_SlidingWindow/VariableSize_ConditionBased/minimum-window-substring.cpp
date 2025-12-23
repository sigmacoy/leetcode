#include <bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        int n = s.length();
        int m = t.length();
        if(m > n) return "";

        unordered_map<char, int> t_freq;
        for(char ch : t) t_freq[ch]++;

        int req = t_freq.size();

        unordered_set<char> t_uSet(t.begin(), t.end());
        vector<pair<char, int>> arr;
        for (int i = 0; i < n; i++) {
            if (t_uSet.count(s[i])) {
                arr.push_back({s[i], i});
            }
        }

        // sugod sliding window
        unordered_map<char, int> window_freq;
        int formed = 0;
        
        int L = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int R = 0; R < arr.size(); R++){
            char ch = arr[R].first;
            window_freq[ch]++;

            if(window_freq[ch] == t_freq[ch]){
                formed++;
            }

            while(L <= R && formed == req){
                int windowS = arr[L].second;
                int windowE = arr[R].second;
                int len = windowE - windowS + 1;

                if(len < minLen){
                    minLen = len;
                    start = windowS;
                }
                
                char leftCh = arr[L].first;
                window_freq[leftCh]--;
                if(window_freq[leftCh] < t_freq[leftCh])
                    formed--;
                
                L++;
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};
// time: O(m + n)
// space: O(n)

/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/