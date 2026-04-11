// MUTual EXclusion primitive
// Prevents race conditions

// NOTES:
// 0. Only one thread can lock a mutex at a time
// 1. Use with lock_guard or unique_lock for RAII
// 2. Always lock for the minimum necessary time
// 3. Avoid deadlock by locking mutexes in consistent order

// TYPES:
// mutex           - Basic mutual exclusion
// recursive_mutex - Same thread can lock multiple times
// timed_mutex     - Try to lock with timeout
// shared_mutex    - Multiple readers, single writer

// PROGRAM:
#include <mutex>
using namespace std;

mutex mtx;
int counter = 0;

void increment() {
    lock_guard<mutex> lock(mtx);  // RAII lock
    counter++;                     // Automatically unlocks when out of scope
}

// lock_guard    - Simple RAII lock (cannot unlock manually)
// unique_lock   - More flexible (can unlock/lock manually)
