// q.push(x), q.pop(): Insert/remove element.
// q.front(), q.back(): Get front/back element.
// q.empty(), q.size(): Check size or if empty.

// ----------------------------------------------

// For priority_queue (Max/Min Heap)

// Default: std::priority_queue<int> (max heap). Decreasing (LARGEST ELEMENT AT THE LEFT SIDE)
// automatically sorted
// pq.push(10);
// pq.push(5);
// pq.push(20);

// Order in memory: [20, 5, 10] (not fully sorted, but 20 is at the top)

// TOP AND POP IS AT THE LEFT SIDE MOST.

// -----------------------------------------------------------------------
// Min heap: std::priority_queue<int, std::vector<int>, std::greater<int>>.

// For deque

// d.push_front(x), d.push_back(x), d.pop_front(), d.pop_back().


// -------------------------- FIFO First In First Out

// q.push(2); Queue: [2]
// q.push(5); Queue: [2, 5]
// q.push(10) Queue: [2, 5, 10]

// std::cout << q.front(); Output: 2 (front element)
// q.pop();                Removes 2, queue: [5, 10]
// std::cout << q.front(); Output: 5 (new front element)
