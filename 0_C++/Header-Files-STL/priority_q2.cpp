// Example
    // class Solution {
    //     public:
    //         vector<string> findRelativeRanks(vector<int>& score) {
    //             int n = score.size();
    //             priority_queue <pair<int, int>> pq; // score, index
    //             vector<string> result(n); // store ranks
        
    //             for(int i = 0; i < n; i++) pq.push({score[i], i});
        
    //             vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
                
    //             int rank = 1;
    //             while(!pq.empty()){
    //                 int idx = pq.top().second; // get index of athlete
    //                 pq.pop();
        
    //                 if(rank <= 3){
    //                     result[idx] = medals[rank - 1]; // assign medal ranks
    //                 } else result[idx] = to_string(rank);
        
    //                 rank++;
    //             }
        
    //             return result;
    //         }
    //     };

// 