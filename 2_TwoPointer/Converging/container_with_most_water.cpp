#include "stdc++.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int maxArea = 0;
        while(l <= r){
            int width = r - l;
            int minH = min(height[l], height[r]);
            int area = width * minH;

            maxArea = max(maxArea, area);
            
            if(height[l] > height[r]){
                r--;
            } else l++;
        }

        return maxArea;
    }
};