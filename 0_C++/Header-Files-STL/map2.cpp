#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int, int, greater<int>> mp;  // Sorts keys in descending order

    int key = 1;
    int value = 2;
    mp.insert(make_pair(key, value));
    mp.insert({key, value});

    for(auto p : mp) {
        cout << p.first << " " << p.second << endl;
    }

}

// O(log n) per insertion — same as regular map, just different order.
// lookup is O(log n) — map is a balanced tree, not a hash table.
