#include <bits/stdc++.h>

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int L = 0, R = arr.size() - 1;

        while(L <= R){
            int mid = L + (R - L) / 2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k) L = mid + 1;
            else R = mid - 1;
        }

        return L + k;

    }
};
/*
If missing < k: Not enough missing numbers yet → search right half (L = mid + 1)
Else: Too many missing numbers → search left half (R = mid - 1)
*/