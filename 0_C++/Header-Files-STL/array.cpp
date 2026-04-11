#include <iostream>
#include <array>

using namespace std;

// NOTICE:
    // 1. std::array is a container that encapsulates fixed-size arrays.
    // 2. Array size is needed at compile time.
    // 3. Assigning by value is actually assigning by value (creates a copy). Pass by value
    
    // 4. Access Elements:
    //    a. at()  // Provides bounds checking
    //    b. []    // Direct access (no bounds checking)
    //    c. front() // Accesses the first element
    //    d. back()  // Accesses the last element
    //    e. data()  // Gives access to the underlying array (returns a pointer)


int main() {
    // Declare and Initialize (using initializer list)
    array<int, 5> myarray1 = {1, 2, 3, 4, 5}; 

    // Declare and Initialize (using uniform initialization)
    array<int, 5> myarray2{1, 2, 3, 4, 5}; 

    // Accessing elements:
    cout << "myarray1[0]: " << myarray1[0] << endl; // Direct access
    cout << "myarray1.at(1): " << myarray1.at(1) << endl; // Using at() with bounds checking

    // Accessing first and last elements:
    cout << "myarray1.front(): " << myarray1.front() << endl;
    cout << "myarray1.back(): " << myarray1.back() << endl;

    // Size of the array:
    cout << "myarray1.size(): " << myarray1.size() << endl;

    // Accessing the underlying array (pointer to the first element):
    int* dataPtr = myarray1.data();
    cout << "myarray1.data(): " << *dataPtr << endl; // Dereference to get the first element

    // Iterating through the array (using range-based for loop):
    cout << "myarray1 elements: ";
    for (int element : myarray1) {
        cout << element << " ";
    }
    cout << endl;

    // Using iterators:
    cout << "myarray2 elements (using iterators): ";
    for (auto it = myarray2.begin(); it != myarray2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

// sort(arr, arr + n);