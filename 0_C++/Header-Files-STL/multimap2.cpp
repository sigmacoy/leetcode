


#include <map>
#include <iostream>
using namespace std;

int main() {
    vector<int> arr1 = {1, 1, 2};
    vector<int> arr2 = {10, 20, 30};

    // Using multimap to sort by value
    multimap<int, int> mm; // key = value, value = original number
    for(int i = 0; i < 3; i++){
        mm.insert( {arr1[i], arr2[i]} );
    }

    cout << "Sorted by map values:" << endl;
    for (auto& [value, num] : mm) {
        cout << num << " -> " << value << endl;
    }

    return 0;
}
