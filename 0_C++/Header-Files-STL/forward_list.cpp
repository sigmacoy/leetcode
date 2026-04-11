// TOPIC: forward list In STL!

// 1. This is single linked list what we know from C prgramming language.
// 2. Why forward_list why not single_list?

// 3. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function

// distance(.begin(), .end());
// assign
// front
// empty
// max
// size
// clear
// insert_after
// emplace_after 
// reverse
// sort
// merge 
// splice_after - some data of list2, then place in list1
// unique - remove all duplicates if tapad ang duplicates, if not tapad, it will not remove the duplicate
// remove - 
// remove_if
// resize

#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> list1 = {5, 4, 6, 2};
    forward_list<int> list2 = {7, 6, 1, 9};

    // list1.insert_after(list1.begin(), 8);
    // list1.reverse();
    // list1.splice_after(list1.begin(), list2); // 5 7 6 1 9 4 6 2
    // int size = distance(list2.begin(), list2.end() );

    // list1.remove_if([] (int n)){
    //    return n > 4;    
    //});

    for(auto& elm: list1) cout << elm << endl;

    return 0;
}

