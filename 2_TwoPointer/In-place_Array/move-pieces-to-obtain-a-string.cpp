#include <bits/stdc++.h>
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;

        while(i < n || j < n){
            while(i < n && start[i] == '_') i++;
            while(j < n && target[j] == '_') j++;
            // if both are done
            if(i == n && j == n) return true;
            // if isa ra done
            if(i == n || j == n) return false;
            // if chars not match
            if(start[i] != target[j]) return false;
            // L can only move sa left, so dapat i >= target
            if(start[i] == 'L' && i < j) return false;
            // R can only move sa right, so dapat i <= target
            if(start[i] == 'R' && i > j) return false;

            i++; j++;
        }
        return true;
    }
};
// time O(n)
// space O(1)

/*
Input: start = "_L__R__R_", 
      target = "L______RR"
Output: true
*/