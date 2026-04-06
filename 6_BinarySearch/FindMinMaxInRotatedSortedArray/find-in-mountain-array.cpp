#include <bits/stdc++.h>

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 class MountainArray {
    public:
     int get(int index);
     int length();
 };

class Solution {
    int peakIndex(MountainArray &mountainArr){
        int n = mountainArr.length();
        int L = 0, R = n - 1;
        while(L < R){
            int mid = L + (R - L) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                L = mid + 1;
            } else R = mid;
        }
        return L;
    }
    int BSLeft(MountainArray &mountainArr, int L, int R, int target){
        int mid;
        while(L <= R){
            mid = L + (R - L) / 2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) < target){
                L = mid + 1;
            } else R = mid - 1;
        }
        return -1;
    }
    int BSRight(MountainArray &mountainArr, int L, int R, int target){
        int mid;
        while(L <= R){
            mid = L + (R - L) / 2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target){
                L = mid + 1;
            } else R = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int pIndex = peakIndex(mountainArr);
        int leftRes = BSLeft(mountainArr, 0, pIndex, target);
        if(leftRes != -1){
            return leftRes;
        }
        int rightRes = BSRight(mountainArr, pIndex, n - 1, target);
        return rightRes;
    }
};