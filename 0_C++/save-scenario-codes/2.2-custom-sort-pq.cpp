#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii a, pii b) {
        // if first values are different, 
        // return the one with SMALLER first value
        if (a.first != b.first) return a.first < b.first;
        
        // if first values are the same, 
        // return the one with SMALLER second value
        return a.second > b.second;
    }
};

int main(){
    priority_queue<pii, vector<pii>, cmp> pq;
    return 0;
}