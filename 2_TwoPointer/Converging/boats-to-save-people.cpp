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
                c++;
                l++;
                r--;
            } else {
                c++;
                r--;
            }
        }

        return c;
    }
};
// time O(n log n) - introsort
// space const variables O(1)