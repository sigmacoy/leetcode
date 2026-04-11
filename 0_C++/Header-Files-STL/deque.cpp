
#include <deque>

// METHODS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

// push_back()
// pop_back()
// push_front()
// pop_front()

// dq.front();
// dq.back();
// dq.at(idx);

// int main() {
    //     deque<int> dq;
    //     dq.push_back(1);
    //     dq.push_back(2);
    //     dq.push_back(3);

    //     dq.pop_back(); // Removes 3 (back)

    //     cout << dq.back(); // 2
    // }

// NOTES:
  // 0. std::deque is an indexed sequence container. (same as vector)
      // std::deque -> Array-based deque -> double-ended queue
  // 1. It allows fast insertion at both beginning and end.
    // have push_front and pop_front
    
  // 2. Unlike vector elements of deque are not stored contiguous. (so like linked list?)
  // 3. It uses individual allocated fixed size array, with additional bookkeeping, meaning index based access to deque
  //    must perform two pointer dereference, but in vector we get in one dereference.
  // 4. The storage of a deque is automatically expanded and contracted as needed.
  // 5. Expansion of deque is cheaper than expansion of vector.
  // 6. A deque holding just one element has to allocate its full internal array 
        // (e.g. 8 times the object size on 64-bit libstdc++; 
        // in libc++, 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).
        // useful for larger datasets
  // TIME COMPLEXITY:
  // Random access - constant O(1)
  // Insertion or removal of elements at the end or beginning - constant O(1)
  // Insertion or removal of elements (at the middle) - linear O(n)

#include <iostream>
#include <deque>
using namespace std;

int main() {
  
  deque<int> myDeque;

  myDeque.push_back(10);
  myDeque.push_front(20);

  cout << "Deque elements: ";
  for (int element : myDeque) {
    cout << element << " ";
  }
  cout << endl;

  return 0;
}




// PROGRAM:
#include <iostream>
#include <deque>
using namespace std;

void print(const std::deque<int>& dqu) { for (int num : dqu) cout << num << " "; cout << endl; }

int main() {
    {
        std::deque<int> dqu = {2, 3, 4};
        dqu.push_front(1);
        dqu.push_back(5);
        print(dqu);
    }
    {
        std::deque<int> dq2 = {2, 3, 4};
        dq2.pop_front();
        dq2.pop_back();
        print(dq2);
    }
    return 0;
}