// TOPIC: Container Inside Container Link = https://youtu.be/2QR34zwjWUA?si=0RczaNxIfkIXBhpW

#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector<vector<int>> Tree;
    int edge, n1, n2; // Edge = Arrow

    cin >> edge;
    Tree.resize(edge);

    for (int i = 0; i < edge; ++i) {
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
    }
    
    // Print 
    
    for (const auto& el : Tree) {
        for (const auto& e2 : el) {
            cout << e2 << " "; 
        }
        cout << endl;
    }

    return 0;
}

// 

vector<int> v = {1, 2, 3, 2};

// This does NOT shrink:
auto new_end = remove(v.begin(), v.end(), 2);  // v = {1, 3, ?, ?}
// v.erase(new_end, v.end());  // Now v = {1, 3}
    // ✅ Use .erase() when removing by index
    // ✅ Use remove + erase when removing by value

// v.reserve(value) -> Avoids multiple reallocations (performance boost);
    // Prevents iterator invalidation

// vector<vector<int>> arr(n, vector<int>(m));
// vector<vector<int>> arr(n, vector<int>(m, 0)); ==> Declare all by zero

// push_back(val)
// pop_back(val)
// back()
// front()
// NO POP_FRONT IN VECTOR. NO!

//

// str1.compare(pos, len, str2)
    // It compares the substring of str1 starting at index pos, with length len, to the full string str2.
    // It returns:
    // 0 → if the two are equal
    // < 0 → if the substring is lexicographically less
    // > 0 → if the substring is greater

// str1.substr(pos, len) -> returns a substring of str1 starting at position pos with length len.
    // string str1 = "HelloWorld";
    // string sub = str1.substr(0, 5);
    // Output: Hello