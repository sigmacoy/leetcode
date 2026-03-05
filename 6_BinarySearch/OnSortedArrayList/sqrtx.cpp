#include <bits/stdc++.h>

class Solution {
public:
    int mySqrt(int x) {
        int L = 1, R = x;

        while(L <= R){
            int mid = L + (R - L) / 2;
            // check if mid * mid <= x
            // pero since ma integer overflow man ang mid * mid
            if(mid <= x / mid){
                L = mid + 1;
            } else R = mid - 1;
        }

        return R;
    }
};