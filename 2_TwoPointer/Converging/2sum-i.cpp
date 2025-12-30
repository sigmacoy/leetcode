#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int l = 0, r = n - 1;
        while(l < r){
            int sum = arr[l].first + arr[r].first;
            if(sum == target){
                return {arr[l].second, arr[r].second};
            } else if(sum > target){
                r--;
            } else {
                l++;
            }
        }

        return {-1, -1};
    }
};
// sort is O(n log n), worst case at O(n^2)
// space O(n)

// LINEAR TIME SOLUTION -> most optimized
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (mp.count(need)) return {mp[need], i};
        mp[nums[i]] = i;
    }
    return {};
}