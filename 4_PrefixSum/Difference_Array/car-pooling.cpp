#include <bits/stdc++.h>
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001] = {0};
        for(auto& t : trips){
            stops[t[1]] += t[0];
            stops[t[2]] -= t[0];
        }
        int pSum = 0;
        for(int i = 0; i <= 1000; i++){
            pSum += stops[i];
            if(pSum > capacity) return false;
        }
        return true;
    }
};