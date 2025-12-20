#include <bits/stdc++.h>
class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIdx = 0;
        int i = 0;

        while (i < chars.size()){
            char currCh = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == currCh){
                i++;
                count++;
            }

            chars[writeIdx++] = currCh;

            if(count > 1){ // if more than 1
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