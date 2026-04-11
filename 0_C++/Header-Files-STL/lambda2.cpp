// auto add = [](int a, int b) { return a + b; };
// cout << add(3, 4);  Output: 7

// You don’t have to use them if you prefer named functions.
// C++ feature

// class Solution {
//     public:
//         static bool customCompare(const string &a, const string &b) {
//             if (a.size() != b.size()) 
//                 return a.size() > b.size(); // if not same length, return greater 
//             return a > b; // if same length, sort lexicographically. return greater number digit
//         }
    
//         string kthLargestNumber(vector<string>& nums, int k) {
//             sort(nums.begin(), nums.end(), customCompare);
//             return nums[k-1];
//         }
// };
    

// class Solution {
//     public:
//         string kthLargestNumber(vector<string>& nums, int k) {
//             // Custom sorting: Sort by length first, then lexicographically
//             sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
//                 return a.size() == b.size() ? a > b : a.size() > b.size();
//             });
    
//             return nums[k-1]; // k-th largest number
//         }
//     };

// int minOperations(vector<int>& nums) {
    // auto flip = [](vector<int> & nums, int i){
    //     nums[i] = (nums[i] == 0) ? 1 : 0;
    // };
    //      int res = 0;
    //      for(int i = 0; i < nums.size() - 2; i++){
    //          if(nums[i] == 0){
    //              flip(nums, i);
    //              flip(nums, i + 1);
    //              flip(nums, i + 2);
    //              res++;
    //          }
    //      }

    //      return -1;
    //      }
    // };
    
// remove duplicates
    // auto remove_duplicates = [](vector<int>& v) -> void {
    //     v.erase(unique(begin(v), end(v)), end(v));
    // };

// sum of digits
    // auto sumOfDigits = [](int n) -> int {
    //     int sum = 0;
    //     n = abs(n);
    //     while (n > 0) {
    //         sum += n % 10;
    //         n /= 10;
    //     }
    //     return sum;
    // };
