#include <bits/stdc++.h>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // kung all 9s
        int flag = 1;
        for(int num : digits){
            if(num != 9){
                flag = 0;
                break;
            }
        }
        vector<int> ans;
        if(flag){
            ans.push_back(1);
            for(int i = 1; i <= n; i++){
                ans.push_back(0);
            }
            return ans;
        }
        // sugod sa right unya to the left
        for(int i = n - 1; i >= 0; i--){
            if(digits[i] != 9){
                digits[i]++;
                break;
            } else digits[i] = 0;
        }

        return digits;
    }
};
// time
// one whole traverse sa digits
// another same
// O(2n)

// space
// one whole vector only, the parameter itself digits
// O(n)