//  Two Sum II - Input Array Is Sorted

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        int sum = 0;

        vector<int> ans(2);

        while(l < r){
            sum = numbers[l] + numbers[r];
            if(sum == target){
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            } else if(sum < target){
                l++;
            } else r--;
        }
        return ans;
    }
};