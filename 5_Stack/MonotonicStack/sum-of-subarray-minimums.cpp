#include <bits/stdc++.h>
using pii = pair<int, int>; // value, idx
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        int MOD = 1e9 + 7;
        
        stack<pii> sPrev, sNext;
        vector<int> left(n), right(n);

        for(int i = 0; i < n; i++){
            left[i] = i + 1;
            right[i] = n - i;
        }

        for(int i = 0; i < n; i++){
            // find previous less
            while(!sPrev.empty() && sPrev.top().first > arr[i])
                sPrev.pop();
            
            left[i] = sPrev.empty() ? i + 1 : i - sPrev.top().second;
            sPrev.push( {arr[i], i} );

            // find next less
            while(!sNext.empty() && sNext.top().first > arr[i]){
                auto x = sNext.top();
                sNext.pop();
                right[x.second] = i - x.second;
            }
            sNext.push( {arr[i], i} );
        }

        // left = [1, 2, 1, 1]
        // right = [1, 3, 2, 1]

        for(int i = 0; i < n; i++){
            ans = (ans + (long long) arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};
/*
nge - next greater elem
pse - previous smaller elem
nse - next smaller elem 
ple - previous larger elem
nsi - next smaller idx

both use monotonic decreasing stack.

left[i] = number of consecutive elements to the left until we hit a smaller number (plus 1 for itself). 
This is i - index_of_previous_smaller.

right[i] = number of consecutive elements to the right until we hit a smaller number (plus 1 for itself). 
This is index_of_next_smaller - i.
*/