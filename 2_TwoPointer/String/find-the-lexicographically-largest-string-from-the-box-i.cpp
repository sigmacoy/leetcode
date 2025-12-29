#include <bits/stdc++.h>
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if (numFriends == 1) return word;
        string ans = "";
        for(int i = 0; i < n; i++){
            string temp = word.substr(i, n - numFriends + 1);
            ans = max(ans, temp);
        }
        return ans;
    }
};
// time: O(n)
// space: O(1)