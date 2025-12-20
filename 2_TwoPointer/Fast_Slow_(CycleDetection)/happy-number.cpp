#include <bits/stdc++.h>

class Solution {
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // Floyd's cycle detection
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};
// time - O(log n)
// space - O(1)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




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