#include <bits/stdc++.h>
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int> & nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            if(a > 0) break;
            if(i && nums[i - 1] == a) continue; // gi skip ang duplicates, dapat all are unique raba dapat
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum3 = a + nums[l] + nums[r];
                if(sum3 > 0) r--;
                else if(sum3 < 0) l++;
                else{
                    res.push_back( {a, nums[l], nums[r]} );
                    l++; 
                    r--;
                    while(nums[l] == nums[l - 1] && l < r) l++; // skipped duplicates
                }
            }  
        }
        return res;
    }
};