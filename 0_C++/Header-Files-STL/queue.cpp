// TOPIC: queue In C++

// NOTES:
// 0. queue class is a container adapter that gives the programmer the functionality of a queue
// 1. queue is FIFO (first-in, first-out) data structure.
// 2. queue provides only specific set of functions.
// 3. queue allows to push(insert) at back and pop(remove) from front.
// 4. queue gives front(left-most), back, push, pop, empty(boolean value), size.

// PROGRAM:
#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> que) {
  while (!que.empty()) {
    cout << que.front() << " ";
    que.pop();
  }
}

int main() {
  queue<int> que;

  que.push(2);
  que.push(3);
  que.push(4);

  print(que);

  return 0;
}