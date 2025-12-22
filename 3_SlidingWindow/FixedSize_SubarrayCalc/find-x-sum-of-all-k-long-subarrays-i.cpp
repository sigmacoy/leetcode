#include <bits/stdc++.h>

#define pii pair<int, int>

class Solution {
    struct minCmp {
        bool operator()(const pii& a, const pii& b) const {
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
    struct maxCmp {
        bool operator()(const pii& a, const pii& b) const {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }
    };
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue<pii, vector<pii>, minCmp> minH;
        priority_queue<pii, vector<pii>, maxCmp> maxH;

        for(int i = 0; i < k; i++) freq[nums[i]]++;

        for(auto& p : freq){
            minH.push( {p.second, p.first} );
            if(minH.size() > x){
                auto top = minH.top();
                minH.pop();
                maxH.push(top);
            }
        }

        int sum = 0;
        auto temp = minH;
        while(!temp.empty()){
            sum += temp.top().first * temp.top().second;
            temp.pop();
        }
        ans.push_back(sum);

        // sugod sliding window
        for(int i = k; i < n; i++){
            int left = nums[i - k];
            int right = nums[i];
            
            freq[left]--;
            freq[right]++;
            if(freq[left] == 0) freq.erase(left);
            
            minH = priority_queue<pii, vector<pii>, minCmp>();
            maxH = priority_queue<pii, vector<pii>, maxCmp>();
            
            for(auto& p : freq){
                minH.push({p.second, p.first});
                if(minH.size() > x){
                    auto top = minH.top();
                    minH.pop();
                    maxH.push(top);
                }
            }
            
            sum = 0;
            auto temp = minH;
            while(!temp.empty()){
                sum += temp.top().first * temp.top().second;
                temp.pop();
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};
// time: O(nk)
// initial window
//      O(k + F log x)
//      O(k) count freq + O(F log x), where F count of unique freq
// copy and empty a heap of size x for every element in the n-sized array
//      O(nk)

// 2nd solution
// #define pii pair<int, int>
// class Solution {
//     struct minCmp {
//         bool operator()(const pii& a, const pii& b) const {
//             if(a.first == b.first) return a.second > b.second;
//             return a.first > b.first;
//         }
//     };
//     struct maxCmp {
//         bool operator()(const pii& a, const pii& b) const {
//             if(a.first == b.first) return a.second < b.second;
//             return a.first < b.first;
//         }
//     };
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         int n = nums.size();
//         vector<int> ans;
//         unordered_map<int, int> freq;
//         priority_queue<pii, vector<pii>, minCmp> minH;
//         priority_queue<pii, vector<pii>, maxCmp> maxH;

//         for(int i = 0; i < k; i++) freq[nums[i]]++;

//         for(auto& p : freq){
//             minH.push( {p.second, p.first} );
//             if(minH.size() > x){
//                 auto top = minH.top();
//                 minH.pop();
//                 maxH.push(top);
//             }
//         }

//         int sum = 0;
//         auto temp = minH;
//         while(!temp.empty()){
//             sum += temp.top().first * temp.top().second;
//             temp.pop();
//         }
//         ans.push_back(sum);

//         // sugod sliding window
//         for(int i = k; i < n; i++){
//             unordered_map<int, int> freq2;
//             for(int j = i - k + 1; j <= i; j++){
//                 freq2[nums[j]]++;
//             }

//             vector<pii> all;
//             for(auto& p : freq2){
//                 all.push_back( {p.second, p.first} );
//             }

//             sort(all.begin(), all.end(), minCmp() );
//             sum = 0;
//             int limit = min(x, (int)all.size());
//             for(int j = 0; j < limit; j++){
//                 sum += all[j].first * all[j].second;
//             }
//             ans.push_back(sum);
//         }
        
//         return ans;
//     }
// };
// since rebuild freq2
// O(nk)

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 3rd solution
// #define pii pair<int, int>
// struct cmp {
//     bool operator()(const pii &a, const pii &b) const {
//         if (a.first == b.first) return a.second > b.second;
//         return a.first > b.first;
//     }
// };
// class Solution {
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         int n = nums.size();
//         int i = 0;
//         vector<int> ans;
//         unordered_map<int, int> mp;
//         priority_queue<pii, vector<pii>, cmp> pq;
//         for (int j = 0; j < n; ++j) {
//             mp[nums[j]]++;
//             if (j - i + 1 == k) {
//                 for (auto [key, v] : mp) {
//                     pq.push({v, key});
//                     if (pq.size() > x) pq.pop();
//                 }
//                 int ret = 0, cp = x;
//                 while (!pq.empty()) {
//                     ret += pq.top().first * pq.top().second;
//                     pq.pop();
//                 }
//                 ans.push_back(ret);
//                 mp[nums[i]]--;
//                 i++;
//             }
//         }    

//         return ans;
//     }
// };
// Time: O(n × (m + x log x)) where m = unique elements in window
//      x is the parameter from findXSum(nums, k, x) - how many top frequent elements to sum.
// Space: O(m + x) for map and heap
// credits to etawn