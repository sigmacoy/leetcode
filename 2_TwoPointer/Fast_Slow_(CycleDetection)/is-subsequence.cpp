#include <bits/stdc++.h>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int i = 0;
        int count = 0;
        
        while(i < t.length() && count < s.length()){
            if(s[count] == t[i]){
                count++;
            }
            i++;
        }

        return count == s.length();
    }
};
// time O(n)
// space O(1)

/*
Input: s = "abc", t = "ahbgdc"
Output: true
*/