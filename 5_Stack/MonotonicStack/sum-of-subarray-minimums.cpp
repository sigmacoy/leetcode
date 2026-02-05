#include <bits/stdc++.h>
using pii = pair<int, int>;
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
            // for previous less
            while(!sPrev.empty() && sPrev.top().first > arr[i])
                sPrev.pop();
            
            left[i] = sPrev.empty() ? i + 1 : i - sPrev.top().second;
            sPrev.push( {arr[i], i} );

            // for next less
            while(!sNext.empty() && sNext.top().first > arr[i]){
                auto x = sNext.top();
                sNext.pop();
                right[x.second] = i - x.second;
            }
            sNext.push( {arr[i], i} );
        }

        for(int i = 0; i < n; i++){
            ans = (ans + (long long) arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};
/*
NLE (Next Larger Element)
PLE (Previous Larger Element) - Same but to the left.

Both use monotonic decreasing stack.
*/