#include <bits/stdc++.h>

class Solution {
public:
    static int countSetBits(int num) {
        // int count = 0;
        // while (num) {
        //     count += (num & 1);
        //     num >>= 1;
        // }
        // return count;

        return __builtin_popcount(num);

        // BY THE WAY:
        /*
        __builtin_clz(42) = count leading zeros
        __builtin_ctz(42) = count trailing zeros
        */
    }

    static bool compare(int a, int b) {
        int bitCountA = countSetBits(a);
        int bitCountB = countSetBits(b);
        if (bitCountA == bitCountB) {
            return a < b;
        }
        return bitCountA < bitCountB;  
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare); 
        return arr;
    }
};