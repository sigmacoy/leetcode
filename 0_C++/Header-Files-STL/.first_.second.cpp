// Summary: Where .first and .second Work

// Data Structure	                Stores Multiple?	    Sorted?	                    Fast Lookup?
// pair<T1, T2>	                    ❌ No	                ❌ No	                    ❌ No
// vector<pair<T1, T2>>	            ✅ Yes	                ❌ No	                    ❌ No
// map<T1, T2>	                    ✅ Yes	                ✅ Yes (by key)	            ✅ Yes (log n)
// unordered_map<T1, T2>	        ✅ Yes	                ❌ No	                    ✅ Yes (O(1) avg)
// set<pair<T1, T2>>	            ✅ Yes	                ✅ Yes (by first)	        ✅ Yes (log n)
// priority_queue<pair<T1,T2>>	    ✅ Yes	                ✅ Yes (heap order)	        ❌ No

// Which One Should You Use?

// pair<int, int> →                 When storing just two related values.
// vector<pair<int, int>> →         When storing multiple pairs (like adjacency lists in graphs).
// map<int, int> →                  When keys must be sorted.
// unordered_map<int, int> →        When you need fast lookups (O(1) on average).
// set<pair<int, int>> →            When you need sorted unique pairs.
// priority_queue<pair<int, int>> → When working with priority-based problems (like Dijkstra’s algorithm).


