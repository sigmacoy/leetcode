#include <bits/stdc++.h>

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
    
        vector<int> leftBoundary(n, -1);
        vector<int> rightBoundary(n, n);
        
        stack<int> leftStack;
        stack<int> rightStack;
        
        for (int i = n - 1; i >= 0; i--){
            while (!leftStack.empty() && nums[leftStack.top()] > nums[i]){
                leftBoundary[leftStack.top()] = i;
                leftStack.pop();
            }
            leftStack.push(i);
        }
        
        for (int i = 0; i < n; i++){
            while (!rightStack.empty() && nums[rightStack.top()] > nums[i]){
                rightBoundary[rightStack.top()] = i;
                rightStack.pop();
            }
            rightStack.push(i);
        }
        
        int maxScore = 0;
        for (int i = 0; i < n; i++){
            if (leftBoundary[i] < k && rightBoundary[i] > k){
                int subarrayScore = nums[i] * (rightBoundary[i] - leftBoundary[i] - 1);
                maxScore = max(maxScore, subarrayScore);
            }
        }
        
        return maxScore;
    }
};
// calculate the score for the subarray that contains element k

// leftBoundary
//  To find each element’s "previous smaller element" index, which determines how far left a subarray with nums[i] as minimum can extend while including index k.

// leftBoundary[3] = 2 (the index sa iya left element)
// nums[3] == 7
// nums[2] == 3

// (rightBoundary[i] - leftBoundary[i] - 1) is the length of the subarray excluding left and right