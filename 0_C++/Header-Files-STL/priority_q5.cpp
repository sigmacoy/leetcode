/*

simple initialize:

#include <queue>
    priority_queue<int> pq; // Max-heap of integers
    default: vector<int> && less<int>


For minHeap
using pii = pair<int, int>;
priority_queue<pii, vector<pii>, greater<pii>> minHeap;
*/

/*
priority_queue<T, Container, Compare>

priority_queue<a, b, cmp>:

a (T): The Type of data you are storing (e.g., int, string, or a custom struct).
b (Container): The Underlying Container used to store the data (a). It defaults to std::vector<a>. 
    You must specify this if you want to use a custom comparator.

C++ templates are positional. If you want to change the third parameter (cmp), 
    you are forced to explicitly define the second parameter (b), 
    even if you just want the default vector.

*/

/*

bool operator()(const pii& a, const pii& b) const {
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }

is this for a minHeap or maxHeap?
- The > Rule: By using a.first > b.first, 
    5 > 4 diba true? E swap na niya since true man

IN SORT:
    sort(all.begin(), all.end(), minCmp() ); <------------ put () -> para new object


MAKING AGAIN:
    minH = priority_queue<pii, vector<pii>, minCmp>();

*/