// SYNTAX: mult/imap<T1, T2> obj; // where T1 is key type and T2 is value type.

// NOTES:
// 1. Multimap is an associative container that contains a sorted list of key-value pairs,
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// Syntax: std::multimap<char, int, std::greater<>> Multimap;
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We dont have at() and [] functions to get element like we had in std::map.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    std::multimap<char, int> Multimap;

    Multimap.insert(make_pair('a', 1));
    Multimap.insert(make_pair('a', 2));
    Multimap.insert(make_pair('a', 3));
    Multimap.insert(make_pair('b', 4));
    Multimap.insert(make_pair('b', 5));

    // Iterate over multimap
    for (auto& elm : Multimap) {
        cout << elm.first << " " << elm.second << endl;
    }

    cout << endl;

    auto pair = Multimap.find('a');
    cout << pair->first << " " << pair->second << endl;

    cout << endl;

    // get all pairs of given key
    auto range = Multimap.lower_bound('a');
    cout << range->first << " " << range->second << endl; // Output is: a 1

    auto range1 = Multimap.lower_bound('a');
    cout << range1->first << " " << range1->second << endl; // Output is: b 4


    return 0;
}

// Multimap sorted on order based on keys, if keys equals, sort them by values.
// 