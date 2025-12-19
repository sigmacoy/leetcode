#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // m is row, n is column
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if(!head) return {};
        vector<vector<int>> arr(m, vector<int>(n, -1));
        ListNode *curr = head;
        int top = 0, left = 0, right = n - 1, bottom = m - 1;
        int i = 0;
        while(top <= bottom && left <= right && curr){
            i = left;
            while(i <= right && curr){
                arr[top][i] = curr->val;
                curr = curr->next;
                i++;
            }
            top++;
            // cout << "1 ";

            i = top;
            while(i <= bottom && curr){
                arr[i][right] = curr->val;
                curr = curr->next;
                i++;
            }
            right--;
            // cout << "2 ";

            if(top <= bottom){
                i = right;
                while(i >= left && curr){
                    arr[bottom][i] = curr->val;
                    curr = curr->next;
                    i--;
                }
                bottom--;
            }
            // cout << "3 ";
            
            if(left <= right){
                i = bottom;
                while(i >= top && curr){
                    arr[i][left] = curr->val;
                    curr = curr->next;
                    i--;
                }
                left++;
            }
            // cout << "4 ";
        }
        
        return arr;
    }
};