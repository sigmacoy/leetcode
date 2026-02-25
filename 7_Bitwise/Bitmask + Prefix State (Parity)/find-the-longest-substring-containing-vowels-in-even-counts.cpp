#include <bits/stdc++.h>

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int mask = 0, maxLength = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);
            
            if (mp.find(mask) != mp.end()){
                maxLength = max(maxLength, i  - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }

        return maxLength;
    }
};
/*
e leetminicowor oep
leetminicowor

bcbcbc
0 -1
00000
answer kay i - -1 so 5 -- 1 so positive 6 answer

aeiou aeiou -> 10
0 (or 00000) -1
00001
00011
00111
01111
11111
11110
11100
11000
10000
00000 -> 9 - -1 -> 10 which is the answer


*/