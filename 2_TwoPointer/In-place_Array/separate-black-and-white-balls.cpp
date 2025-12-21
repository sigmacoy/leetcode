// GREEDY
#include <bits/stdc++.h>

class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        int zeros = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zeros++;
            } else {  // s[i] == '1'
                swaps += zeros;
            }
        }
        
        return swaps;
    }
};
// time: O(n)
// space: O(1)

// 101
// Output: 1

// Brute Force TLE
// class Solution {
// public:
//     long long minimumSteps(string s) {
//         int n = s.length();
//         long long ans = 0;
//         int i = n - 1;
//         while(i >= 0){
//             while(i >= 0 && s[i] == '1') i--;
//             if(i == 0) break;
//             int j = i - 1;
//             while(j >= 0 && s[j] == '0'){ // mangita sha og 1
//                 j--;
//             }
//             if(j < 0) break;
//             // cout << i << " " << j << endl;
//             s[i] = '1';
//             s[j] = '0';
//             ans += (i - j);
//             i--;
//         }
//         return ans;
//     }
// };
// time O(n^2) because of nested while loops