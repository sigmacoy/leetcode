#include <bits/stdc++.h>

using pii = pair<int, int>;

// struct cmp {
//     bool operator()(pii a, pii b){
//         return a.first > b.first;
//     }
// };

// no static coz it is global
bool cmp(pii a, pii b){
    return a.first > b.first;
}

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pii> items;

        for(int i = 0; i < n; i++){
            items.push_back( {values[i], labels[i]} );
        }

        // sort(items.begin(), items.end(), cmp());
        sort(items.begin(), items.end(), cmp);

        unordered_map<int, int> labelCount;
        int sum = 0;
        int c = 0;

        for(auto item : items){
            int val = item.first;
            int label = item.second;

            if(c < numWanted && labelCount[label] < useLimit){
                sum += val;
                c++;
                labelCount[label]++;
            }

            if(c >= numWanted) break;
        }

        return sum;
    }
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PRIORITY QUEUE CUSTOM SORT  -  needed struct cmp bool operator(){}






