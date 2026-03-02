#include <bits/stdc++.h>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> st;
        st.push_back(A[0]);
        for(int i = 1; i < A.size(); i++){
            int num = A[i];
            while(!st.empty() && st.back() > 0 && num < 0){
                int sum = st.back() + num;
                if(sum == 0){
                    st.pop_back();
                    num = 0;
                    break;
                } else if(sum > 0){
                    num = 0;
                    break;
                } else {
                    st.pop_back();
                }
            }
            if(num){
                st.push_back(num);
            }
        }

        return st;
    }
};

/*
5 10 -5 -> 5 10

8 -8 -> []

10 2 -5 -> 10

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3 5 -6 2 -1 4 -> -6 2 4
-6 2 4

If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/