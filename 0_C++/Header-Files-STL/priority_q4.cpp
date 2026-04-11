// Leetcode Problem : 692. Top K Frequent Words

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define pis pair<int, string>

struct cmp {
    bool operator()(pis &a, pis &b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k){
        unordered_map<string, int> mp;

        for(string s : words) mp[s]++;

        priority_queue< pis, vector<pis>, cmp> pq;
        for(auto [key, v] : mp){ // key is string, v is the value count
            pq.push({v, key});
        }

        vector<string> ans;
        while(!pq.empty() && k--){
            auto top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }

        return ans; 
    }
};

//              
/*              priority_queue< T, Container, Compare >
                    T → the type of elements (your pis = pair<int,string>)
                    Container → underlying storage (default = vector<T>)
                    Compare → comparison functor (your cmp)

                    means:
                    pis → each element is pair<int,string>
                    vector<pis> → stores elements in a vector internally

Because in C++ STL, "container" is the formal term for classes that store collections of objects (vector, list, map, etc).
"Data structure" is the general CS concept — STL calls its implementations containers.

*/              