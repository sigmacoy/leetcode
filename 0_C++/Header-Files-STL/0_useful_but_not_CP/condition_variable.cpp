// Thread synchronization primitive
// Used with mutex to wait for events

// NOTES:
// 0. Allows threads to wait for a condition to become true
// 1. Must be used with unique_lock<mutex>
// 2. Prevents busy waiting (spinning)
// 3. Spurious wakeups possible - always check condition in loop

// WHY CONDITION_VARIABLE
// Efficient thread waiting - releases CPU while waiting.

// PROGRAM:
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void worker() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });  // Wait until ready == true
    cout << "Worker thread proceeding\n";
}

int main() {
    thread t(worker);
    this_thread::sleep_for(chrono::seconds(1));
    {
        lock_guard<mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();  // Wake up waiting thread
    t.join();
    return 0;
}

// Common Patterns:
// cv.wait(lock, predicate)  - Wait with condition check
// cv.notify_one()           - Wake one waiting thread
// cv.notify_all()           - Wake all waiting threads