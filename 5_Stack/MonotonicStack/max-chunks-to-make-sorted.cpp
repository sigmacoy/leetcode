#include <bits/stdc++.h>

class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int n = A.size();
        stack<int> s;
        for(int num : A){
            int largest = num;
            while(!s.empty() && s.top() > num){
                largest = max(largest, s.top());
                s.pop();
            }
            s.push(largest);
        }

        return s.size();
    }
};