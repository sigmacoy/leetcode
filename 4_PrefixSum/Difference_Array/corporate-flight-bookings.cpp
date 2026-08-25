#include <bits/stdc++.h>
// 1985 ms
class Solution1 {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int len = bookings.size();
        vector<int> ans(n, 0);
        for(auto& a : bookings){
            int val = a[2];
            int start = a[0] - 1;
            int end = a[1] - 1;
            for(int i = start; i <= end; i++){
                ans[i] += val;
            }
        }
        return ans;
    }
};
// 0 ms
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0);
        for(int i = 0; i < bookings.size(); i++){
            int l = bookings[i][0];
            int r = bookings[i][1];

            diff[l] += bookings[i][2];
            diff[r+1] -= bookings[i][2];
        }
        vector<int> ans(n);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=diff[i];
            ans[i-1]=sum;  
        } 
        return ans;
    }
};