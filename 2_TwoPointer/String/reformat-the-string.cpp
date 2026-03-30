#include <bits/stdc++.h>

class Solution {
public:
    string reformat(string s) {
        vector<char> letters, digits;
        for(char ch : s){
            if(isalpha(ch)){
                letters.push_back(ch);
            } else {
                digits.push_back(ch);
            }
        }
        int lSz = letters.size();
        int dSz = digits.size();
        if(abs(lSz - dSz) > 1){
            return "";
        }

        bool letterFirst = (lSz > dSz);

        string ans = "";
        int i = 0, j = 0;

        while(i < lSz || j < dSz){
            if(letterFirst){
                if(i < lSz) ans += letters[i++];
                if(j < dSz) ans += digits[j++];
            } else {
                if(j < dSz) ans += digits[j++];
                if(i < lSz) ans += letters[i++];
            }
        }

        return ans;
    }
};