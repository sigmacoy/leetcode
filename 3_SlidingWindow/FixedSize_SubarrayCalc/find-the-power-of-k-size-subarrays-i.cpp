#include <bits/stdc++.h>
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if(k == 1){
            for(int num : nums) ans.push_back(num);
            return ans;
        }
        int consec = 1; 
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1] + 1){
                consec++;
            } else consec = 1;

            if(i >= k - 1){ 
                if(consec >= k){
                    ans.push_back(nums[i]); 
                } else ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
// time O(n) - sliding window
// space O(1)

/*
Input: nums = [1,2,3,4,3,2,5], k = 3
Output: [3,4,-1,-1,-1]
*/

// ~~~~~~~~~~~~~~~~~~~
// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i = 0 ; i <= n - k; i++){
//             bool flag = true;
//             for(int j = i + 1; j < i + k; j++){
//                 if(nums[j] - nums[j-1] != 1){
//                     flag = false;
//                     break;
//                 }
//             }  

//             if(flag){   
//                 ans.push_back(nums[i + k - 1]);
//             } else ans.push_back(-1);
            
//         }
//         return ans;   
//     }
// };
// // time O(n x k) where k is the length of fixed sized subarray
// // space O(1)