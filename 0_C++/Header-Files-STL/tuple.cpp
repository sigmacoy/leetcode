// multi-dimensional state tracking -> group values logically

// pair<> only supports 2 elements.
// tuple<> can hold 3, 4, or more values, e.g. tuple<int, int, int, int> — great for multidimensional states in algorithms.

// Accessing tuple values
    // tuple<int, int, int> t = {1, 2, 3};

    // int x = get<0>(t);  // x = 1
    // int y = get<1>(t);  // y = 2
    // int z = get<2>(t);  // z = 3

// BFS with extra state:
    // queue<tuple<int, int, int>> q;  // row, col, steps
    // q.push({0, 0, 0});

// Priority Queue with multiple keys:
    // priority_queue<tuple<int, int>> pq;  // {weight, node}

// Returning multiple values from a function:
    // tuple<int, int> getMinMax() {
    //     return {minVal, maxVal};
    // }

// Sorting by multiple criteria:
    // vector<tuple<int, int>> a = {{2, 5}, {1, 3}};
    // sort(a.begin(), a.end());  // sort by first, then second


#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    queue<tuple<int, int, int, int>> q;         // pwede rapud tulo ra

    q.push({1, 2, 3, 4});
    q.push({5, 6, 7, 8});

    auto front = q.front(); q.pop();
    cout << get<0>(front) << "\n";

    cout << boolalpha << q.empty() << "\n";

    stack<tuple<int, int, int, int>> s;

    s.push({10, 20, 30, 40});
    s.push({50, 60, 70, 80});

    auto top = s.top(); s.pop();
    cout << get<0>(top) << "\n";

    cout << boolalpha << s.empty() << "\n";

    return 0;
}

// EXAMPLES:

tuple<int, int, int, int> t = {10, 20, 30, 40};

    // Access elements
        // get<0>(t);  // → 10
        // get<1>(t);  // → 20
        // get<2>(t);  // → 30
        // get<3>(t);  // → 40

    // Modify elements
        // get<0>(t) = 99;  // change first value to 99

    // Get size of tuple (compile-time constant)
        // tuple_size<decltype(t)>::value;  // → 4

    // Get type of element at index
        // tuple_element<2, decltype(t)>::type x;  // x is int

    // Tie to unpack elements
        // int a, b, c, d;
        // tie(a, b, c, d) = t;  // a=99, b=20, c=30, d=40

    // Make a tuple easily
        // auto tup = make_tuple(1, 2, 3, 4);