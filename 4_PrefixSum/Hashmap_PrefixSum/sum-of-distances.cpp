#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);

        for(auto [val, indices] : mp){
            int m = indices.size();
            if(m == 1) continue;
            vector<long long> prefix(m + 1, 0);
            for(int i = 0; i < m; i++){
                prefix[i + 1] = prefix[i] + indices[i];
            }
            for(int i = 0; i < m; i++){
                long long left = (long long)indices[i] * i - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) -
                                (long long) indices[i] * (m - i - 1);
                ans[indices[i]] = left + right;
            }
        }
        
        return ans;
    }
};

// BRUTE FORCE 1065/1068 TLE
// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         unordered_map<int, unordered_set<int>> mp; // num and list of idx
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             // mp[ nums[i] ].push_back(i);
//             mp[nums[i]].insert(i);
//         }
//         vector<long long> ans;
//         for(int i = 0; i < n; i++){
//             long val = 0;
//             // for(int j = 0; j < mp[nums[i]].size(); j++){
//             //     if(mp[nums[i]].count(i)) continue;
//             //     val += abs()
//             // }
//             for (int x : mp[nums[i]]) {
//                 if(x == i) continue;
//                 val += (long long) abs(i - x);
//             }
//             ans.push_back(val);
//         }
//         return ans;
//     }
// };