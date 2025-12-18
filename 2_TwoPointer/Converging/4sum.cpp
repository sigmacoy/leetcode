#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> resSet;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                unordered_set<long long> s;

                for(int k = j + 1; k < n; k++){
                    long long sum = (long long) nums[i] + nums[j] + nums[k];
                    long long last = (long long) target - sum;

                    if(s.find(last) != s.end()){
                        vector<int> curr = {nums[i], nums[j], nums[k], (int)last};
                        sort(curr.begin(), curr.end());
                        resSet.insert(curr);
                    }

                    s.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(resSet.begin(), resSet.end());

    }
};