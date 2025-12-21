#include <bits/stdc++.h>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int c = 0;
        int l = 0, r = n - 1;

        while(l <= r){
            int sum = people[l] + people[r];
            if(sum <= limit){
                l++;
            }
            c++;
            r--;
        }

        return c;
    }
};
// time O(n log n) - introsort
// space const variables O(1)

/*
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
*/