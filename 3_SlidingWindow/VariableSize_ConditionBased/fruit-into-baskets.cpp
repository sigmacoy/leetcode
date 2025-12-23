#include <bits/stdc++.h>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        int L = 0;
        unordered_map<int, int> mp;
        for(int R = 0; R < n ; R++){
            mp[fruits[R]]++;
            while(mp.size() > 2){
                mp[fruits[L]]--;
                if(mp[fruits[L]] == 0){
                    mp.erase(fruits[L]);
                }
                L++;
            }
            maxLen = max(maxLen, R - L + 1);
        }
        
        return maxLen;
    }
};
// time: O(n)
// space: O(2)
/*
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2]
*/