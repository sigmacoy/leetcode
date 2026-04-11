#include <iostream>
#include <vector>

using namespace std;

// NOTES:
// 1. std::vector - sequence container (will be stored sequentially, not randomly)
//                - Dynamic Array or Array List. 

// Go linked list if don't know size, construct tree. 

// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.
// Double the size if size is kuwangan, dynamically

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

int main() {
    // Declarations
    vector<int> arr1; // Empty vector
    vector<int> arr2(5, 20); // 5 elements, each initialized to 20
    vector<int> arr3 = {1, 2, 3, 4, 5}; // Initializer list
    vector<int> arr4{1, 2, 3, 4, 5}; // Uniform initialization

    // Accessing Elements
    arr2[3] = 10; // Direct access (no bounds checking) => NOT Exception safe
    arr2.at(3) = 10; // Access with bounds checking => Exception safe

    cout << "arr2[3]: " << arr2[3] << endl;
    cout << "arr2.at(3): " << arr2.at(3) << endl;

    cout << "arr3.front(): " << arr3.front() << endl; // First element
    cout << "arr3.back(): " << arr3.back() << endl;  // Last element

    cout << "arr3.data(): " << *(arr3.data()) << endl; // Pointer to the first element


    // Modifiers
    arr1.push_back(100); // Add element to the end
    arr1.push_back(200);
    cout << "arr1 size after push_back: " << arr1.size() << endl;


    arr3.insert(arr3.begin() + 2, 99); // Insert 99 at index 2
    cout << "arr3 after insert: ";
    for (int x : arr3) cout << x << " "; cout << endl;

    arr3.emplace(arr3.begin() + 1, 55); // In-place insertion of 55 at index 1 (more efficient than insert in some cases)
    cout << "arr3 after emplace: ";
    for (int x : arr3) cout << x << " "; cout << endl;


    arr1.emplace_back(300); // In-place addition to the end
    cout << "arr1 size after emplace_back: " << arr1.size() << endl;

    arr1.pop_back(); // Remove the last element
    cout << "arr1 size after pop_back: " << arr1.size() << endl;


    arr2.resize(3); // Resize to 3 elements (truncates the end)
    cout << "arr2 size after resize(3): " << arr2.size() << endl;

    arr2.resize(5, 50); // Resize to 5, new elements are initialized to 50
    cout << "arr2 size after resize(5, 50): " << arr2.size() << endl;
    for (int x : arr2) cout << x << " "; cout << endl;


    vector<int> arr5 = {6, 7, 8};
    arr3.swap(arr5); // Swap contents with arr5
    cout << "arr3 after swap: ";
    for (int x : arr3) cout << x << " "; cout << endl;
    cout << "arr5 after swap: ";
    for (int x : arr5) cout << x << " "; cout << endl;


    arr3.erase(arr3.begin() + 1); // Remove element at index 1
    cout << "arr3 after erase: ";
    for (int x : arr3) cout << x << " "; cout << endl;


    arr1.clear(); // Remove all elements
    cout << "arr1 size after clear: " << arr1.size() << endl;

    return 0;
}

// insert(): Inserts elements at a specified position.
// emplace(): Constructs elements in-place at a specified position (potentially more efficient than insert).

// push_back(): Adds an element to the end of the vector.
// emplace_back(): Constructs an element in-place at the end of the vector (potentially more efficient than push_back).

// pop_back(): Removes the last element.
// erase(): Removes elements at a specified position or range.
// resize(): Changes the number of elements (can add or remove).
// swap(): Exchanges the contents with another vector.
// clear(): Removes all elements.

// .back() == > The most right.
// .front() 

// insert():  Typically copies or moves an existing object into the vector. 
//      If you're inserting a complex object, this can involve creating a temporary copy 
//      or moving the object's data, which can have some overhead.

// emplace(): Constructs the new element directly in the vector's memory 
//      at the specified position. It avoids the creation of a temporary object 
//      and the subsequent copy or move.  This can be significantly more efficient, 
//      especially for complex objects where construction is cheaper than copying or moving.

// insert() is like: You already have a drawing finished on a separate piece of paper. 
//     You then carefully copy that drawing onto a new page and slide it into your binder.  
//     Or, if the drawing is on thin paper, you might carefully move it over. 
//     Either way, you had to handle the drawing twice.

// emplace() is like: You have all your art supplies ready (pencils, crayons, etc.). 
//     You draw directly onto a blank page that's already in your binder. You skip the extra step of drawing it somewhere else first.

    // vector<int> v = {9, 11, 15, 56};
    // // Printing all elements in reverse order
    // for (auto it = v.rbegin(); it != v.rend(); ++it)
    //     cout << *it << " ";
    // Output: 56 15 11 9 



// VECTOR insert
    // insert("POSITION TO INSERT ELEMENT/s" , "START OF THE RANGE" , "END OF THE RANGE") so 3 inputs
    // vector<int> v = {1, 2, 4, 5};

    // Insert single element at index 2 (before 4)
    // v.insert(v.begin() + 2, 3);

    // Insert multiple elements at index 1
    // v.insert(v.begin() + 1, 2, 10); // Inserts two 10s before index 1

    // Insert elements from another vector
    // vector<int> v = {1, 2, 3};
    // vector<int> extra = {7, 8, 9};
    // v.insert(v.end(), extra.begin(), extra.end()); // Insert at the end
    // OUTPUT: 
    // v = {1, 2, 3, 7, 8, 9};

// Insert at the left most of the vector    
    // nums.insert(nums.begin(), 1);

// COUNT
    // vector<int> array = {1, 2, 2, 3};
    // cout << count(arr.begin(), arr.end(), 2); // ✅ Output: 2

// Remove then erase
    // vector<string> word1 = {"leetcode", "is", "amazing", "as", "is"};

    // Remove "is" from the vector
    // word1.erase(remove(word1.begin(), word1.end(), "is"), word1.end());

// Remove using unique function
    // vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    // auto newEnd = unique(nums.begin(), nums.end());
    // nums.erase(newEnd, nums.end());
    // OR
    // nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end()); ==> Vector must be sorted first





// push_back vs emplace_back
            // #include <vector>
            // #include <iostream>
            // using namespace std;

            // struct Item {
            //     int id;
            //     string name;
            //     Item(int i, const string& n) : id(i), name(n) {
            //         cout << "Constructed: " << name << endl;
            //     }
            //     // Copy constructor
            //     Item(const Item& other) : id(other.id), name(other.name) {
            //         cout << "Copied: " << name << endl;
            //     }
            // };

            // int main() {
            //     vector<Item> items;

            //     // push_back: Makes a temporary Item outside, then copies it into the vector
            //     items.push_back(Item(1, "Apple"));  // Output: Constructed Apple -> Copied Apple

            //     // emplace_back: Builds the Item directly inside the vector (no copy!)
            //     items.emplace_back(2, "Banana");    // Output: Constructed Banana

            //     return 0;
            // }