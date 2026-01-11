#include <bits/stdc++.h>
class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIdx = 0;
        int i = 0;
        int n = chars.size();

        while (i < n){
            char currCh = chars[i];
            int count = 0;

            while(i < n && chars[i] == currCh){
                i++;
                count++;
            }

            chars[writeIdx++] = currCh;

            if(count > 1){ // if more than 1, input is ["a"] -> dapat ["a"] rajud na
                for(char c : to_string(count)){ // naa nyay numbers 10 and above
                    chars[writeIdx++] = c;
                }
            }
        }

        return writeIdx;
    }
};
// time O(n)
// space O(1)
/*
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
*/