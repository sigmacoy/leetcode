#include <bits/stdc++.h>

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;

        while(L < R){
            int mid = L + (R - L) / 2;

            if(mid % 2 == 0){ // even idx
                if(nums[mid] == nums[mid + 1]){
                    L = mid + 2;
                } else R = mid;
            } else { // odd idx
                if(nums[mid] == nums[mid - 1]){
                    L = mid + 1;
                } else R = mid - 1;
            }
        }

        return nums[L];
    }
};
/*
[1,1,2,3,(3), 4,4,8,8] n = 9
[1,1,2,2,(3), 3,4,8,8] n = 9
*/