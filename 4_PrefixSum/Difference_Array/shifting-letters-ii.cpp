#include <bits/stdc++.h>
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);

        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                diff[start] += 1;
                if (end + 1 < n) diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                if (end + 1 < n) diff[end + 1] += 1;
            }
        }

        // prefix sum
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift = (shift + diff[i]) % 26;

            // Handle negative shifts by adding 26
            int new_char = (s[i] - 'a' + shift + 26) % 26;
            s[i] = 'a' + new_char;
        }

        return s;
    }
};
