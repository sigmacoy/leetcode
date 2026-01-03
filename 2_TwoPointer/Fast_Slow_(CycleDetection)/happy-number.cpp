#include <bits/stdc++.h>
class Solution {
    int help(int n){
        int sum = 0;
        while(n){
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = help(n);

        while(slow != fast && fast != 1){
            slow = help(slow);
            fast = help(help(fast));
        }

        return fast == 1;
    }
};
/* 
time O(k log m)
k = number of itr antod abot 1
m = number of digits in curr number
but in worst case:
O(log n * log (log n) )

space: O(1)
*/

/*
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/



// Not two pointer solution but valid:
// class Solution {
//     int f(int n){
//         int sum = 0;
//         while(n){
//             int digit = n % 10;
//             n /= 10;
//             sum += digit * digit;
//         }
//         return sum;
//     }
// public:
//     bool isHappy(int n) {
//         unordered_set<int> visited;
//         while(true){
//             if(n == 1) return true;
//             n = f(n);
//             if(visited.count(n) == 1) return false;
//             visited.insert(n);
//         }
//         return true; 
//     }
// };