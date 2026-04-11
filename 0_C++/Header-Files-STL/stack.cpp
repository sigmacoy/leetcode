// st.push(x) at the TOP of the stack
// st.pop(): Push/pop elements. Deletes the most recent entered element of the stack
// st.top(): Get top element.
// st.empty(), st.size(): Check if empty or size.
// .size()

// -------------------------- LIFO Last In First Out

// s.push(2);  Stack: [2] (Append sha in python)
// .swap();
// .emplace();


// cout << s.top(); Output: 10 (top element)
// s.pop();              Removes 10, stack: [5, 2]
// cout << s.top(); Output: 5 (new top element)

// top and pop at the left most side

// stack<int> st;

// ----------------------------------------------------------------------------------------------------------
// TOPIC: stack In C++ !

// NOTES:
// 0. stack class is a container adapter that gives the programmer the functionality of a stack.
// 1. Internally it uses deque STL container.
// 2. It is LIFO (last-in, first-out) data structure.
// 4. stack allows to push(insert) and pop(remove) only from back.

// FUNCTIONS PROVIDED:
// empty() - Returns whether the stack is empty - Time Complexity : O(1)
// size() - Returns the size of the stack - Time Complexity : O(1)
// top() - Returns a reference to the top most element of the stack - Time Complexity : O(1)
// push(g) - Adds the element 'g' at the top of the stack - Time Complexity : O(1)
// pop() - Deletes the top most element of the stack - Time Complexity : O(1)

// PROGRAM:
#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> stk) {
  while (!stk.empty()) {
    cout << stk.top() << endl;
    stk.pop(); // Remove from the back
  }
}

int main() {
  stack<int> stk;

  stk.push(2);
  stk.push(3);
  stk.push(4);

  print(stk);

  return 0;
}
